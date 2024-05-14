#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Creation Form", 145, 137) {
	this->_target = "undefined";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	AForm("Presidential Creation Form", 145, 137) {
		this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) {
	if (this != &obj)
		*this = obj;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	PresidentialPardonForm::executeBehaviour() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."	<< std::endl;
}
