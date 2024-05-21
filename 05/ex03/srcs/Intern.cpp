#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &obj) {
	if (this != &obj)
		*this = obj;
}

Intern	&Intern::operator=(const Intern &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	Intern::deleteUnusedForms(AForm *forms[], int i) {
	while (i < 3)
		delete forms[i++];
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	AForm	*forms[FORMS_QUANTITY] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
	};
	std::string	formNames[] = {
		"Shruberry Creation Form",
		"Robotomy Request Form",
		"Presidential Pardon Form"
	};

	for (int i = 0; i < FORMS_QUANTITY; i++) {
		if (formNames[i] == name) {
			deleteUnusedForms(forms, i + 1);
			return forms[i];
		}
		delete forms[i];
	}
	std::cerr << name << " form doesn't exist." << std::endl;
	return NULL;
}
