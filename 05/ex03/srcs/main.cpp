#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <fstream>

void	presidentialTest() {
	Intern	intern;
	Bureaucrat	b;
	AForm	*form;

	form = intern.makeForm("Robotomy Request Form", "oui");

	b = Bureaucrat("Michel", 150);
	try {
		if (form)
			form->execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	b = Bureaucrat("Michel", 1);
	try {
		if (form)
			form->execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete form;
}

void	robotomyTest() {
	Intern	intern;
	Bureaucrat	b;
	AForm	*form;

	form = intern.makeForm("Robotomy Request Form", "oui");

	b = Bureaucrat("Michel", 150);
	try {
		if (form)
			form->execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	b = Bureaucrat("Michel", 1);
	try {
		if (form)
			form->execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete form;
}

void	shruberryTest() {
	Intern	intern;
	Bureaucrat	b;
	AForm	*form;

	form = intern.makeForm("Shrubbery Creation Form", "oui");

	b = Bureaucrat("Michel", 150);
	try {
		if (form)
			form->execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	b = Bureaucrat("Michel", 1);
	try {
		if (form)
			form->execute(b);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete form;
}

int	main() {
	presidentialTest();
	robotomyTest();
	shruberryTest();

	Intern	intern;
	AForm	*form = intern.makeForm("random", "random");
	std::cout << "form address: " << form << std::endl;
}
