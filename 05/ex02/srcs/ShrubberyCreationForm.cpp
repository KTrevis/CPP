#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137) {
	this->_target = "undefined";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm("Shrubbery Creation Form", 145, 137) {
		this->_target = target;
}

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

void	ShrubberyCreationForm::executeBehaviour() const {
	std::string		fileName = this->_target + "_shruberry";
	std::ofstream	file(fileName.c_str());

	file << "              v .   ._, |_  .," << std::endl;
	file << "           `-._\\/  .  \\ /    |/_" << std::endl;
	file << "               \\  _\\, y | \\//" << std::endl;
	file << "         _\\_.___\\, \\/ -.\\||" << std::endl;
	file << "           `7-,--.`._||  / / ," << std::endl;
	file << "           /'     `-. `./ / |/_.'" << std::endl;
	file << "                     |    |//" << std::endl;
	file << "                     |_    /" << std::endl;
	file << "                     |-   |" << std::endl;
	file << "                     |   =|" << std::endl;
	file << "                     |    |" << std::endl;
	file << "--------------------/ ,  . \\--------._" << std::endl;
	file.close();
}
