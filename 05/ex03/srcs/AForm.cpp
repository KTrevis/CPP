#include "AForm.hpp"

AForm::AForm(std::string name, uchar signGrade, uchar execGrade): 
	_name(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150)
		throw AForm::GradeTooLowException();
	this->_isSigned = false;
}

AForm::AForm(std::string name, std::string target, uchar signGrade, uchar execGrade): 
	_name(name), _target(target), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150)
		throw AForm::GradeTooLowException();
	this->_isSigned = false;
}

AForm::AForm(): _name("undefined"), _signGrade(1), _execGrade(1) {
	this->_isSigned = false;
}

AForm::~AForm() {}

AForm::AForm(AForm const &obj):
	_name(obj._name), _signGrade(obj._signGrade), _execGrade(obj._execGrade) {
	if (this != &obj)
		*this = obj;
}

AForm	&AForm::operator= (const AForm &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	AForm::beSigned(Bureaucrat &b) {
	if (this->_isSigned) {
		std::cerr << "Already signed" << std::endl;
		return ;
	}
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

uchar	AForm::getExecGrade() const {
	return this->_execGrade;
}

uchar	AForm::getSignGrade() const {
	return this->_signGrade;
}

std::string	AForm::getName() const {
	return this->_name;
}

std::string	AForm::getTarget() const {
	return this->_target;
}

bool	AForm::isSigned() const {
	return this->_isSigned;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	executeBehaviour();
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low.";
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Bureaucraft grade too high.";
}

std::ostream	&operator<<(std::ostream &os, const AForm &form) {
	os << "Form name : " << form.getName() << std::endl;
	os << "Exec grade: " << (int)form.getExecGrade() << std::endl;
	os << "Sign grade: " << (int)form.getSignGrade() << std::endl;
	return os;
}
