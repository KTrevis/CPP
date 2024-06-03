#include "Form.hpp"

Form::Form(std::string name, uchar requiredGrade): _name(name), _requiredGrade(requiredGrade) {
	if (this->_requiredGrade < 1)
		throw Form::GradeTooHighException();
	if (this->_requiredGrade > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = false;
}

Form::Form(): _name("undefined"), _requiredGrade(1) {
	this->_isSigned = false;
}

Form::~Form() {}

Form::Form(Form const &obj): _name(obj._name), _requiredGrade(obj._requiredGrade) {
	if (this != &obj)
		*this = obj;
}

Form	&Form::operator= (const Form &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	Form::beSigned(Bureaucrat &b) {
	if (this->_isSigned) {
		std::cerr << "This form is already signed." << std::endl;
		return ;
	}
	if (b.getGrade() > this->_requiredGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

uchar	Form::getRequiredGrade() const {
	return this->_requiredGrade;
}

std::string	Form::getName() const {
	return this->_name;
}

bool	Form::isSigned() const {
	return this->_isSigned;
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low.";
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Bureaucraft grade too high.";
}
