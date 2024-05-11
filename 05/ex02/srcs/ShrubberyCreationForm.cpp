#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("undefined", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name): AForm(name, 145, 137) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) {
	if (this != &obj)
		*this = obj;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &obj) {
	if (this == &obj)
		return *this;
	return *this;
}
