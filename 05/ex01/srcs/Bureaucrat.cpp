#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

Bureaucrat::Bureaucrat(std::string name, uchar grade): _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(): _name("undefined"), _grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) {
	if (this != &obj)
		*this = obj;
}

Bureaucrat	&Bureaucrat::operator= (const Bureaucrat &obj) {
	if (this == &obj)
		return *this;
	this->_grade = obj._grade;
	return *this;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade cannot be higher than 1.";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade cannot be lower than 150.";
}

const std::string	Bureaucrat::getName() const {
	return this->_name;
}

uchar	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << this->_name << " couldn't sign " << form.getName()
			<< " because its grade is too low." << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade "
		<< (int)b.getGrade() << std::endl;
	return os;
}
