#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm ("Robotomy Request Form", 72, 45) {
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm():
	AForm ("Robotomy Request Form", 72, 45) {
	this->_target = "undefined";
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) {
	if (this != &obj)
		*this = obj;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	RobotomyRequestForm::executeBehaviour() const {
	static int i = 0;

	std::cout << "* DRILLING NOISES *" << std::endl;
	if (i % 2)
		std::cout << this->_target << " has been rotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
	i++;
}
