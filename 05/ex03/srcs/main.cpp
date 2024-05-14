#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>

void	shrubberyTest() {
	std::cout << "SHRUBERRY TEST" << std::endl;
	ShrubberyCreationForm	form("home");
	Bureaucrat				b("Michel", 1);

	/* b.executeForm(form); */
	b = Bureaucrat("Michel", 150);
	b.executeForm(form);
	try {
		form.execute(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	robotomyTest() {
	std::cout << std::endl << "ROBOTOMY TEST" << std::endl;
	RobotomyRequestForm	form("Michel");
	Bureaucrat				b("Michel", 1);

	b.executeForm(form);
	b.executeForm(form);
	b.executeForm(form);
	b = Bureaucrat("Michel", 150);
	b.executeForm(form);
	try {
		form.execute(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	presidentialTest() {
	std::cout << std::endl << "PRESIDENTIAL TEST" << std::endl;
	PresidentialPardonForm	form;
	Bureaucrat				b("Michel", 1);

	b.executeForm(form);
	b = Bureaucrat("Michel", 150);
	b.executeForm(form);
	try {
		form.execute(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main() {
	shrubberyTest();
	robotomyTest();
	presidentialTest();
}
