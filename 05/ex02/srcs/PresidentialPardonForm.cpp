#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Creation Form", "undefined", 145, 137) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	AForm("Presidential Creation Form", target, 145, 137) {}

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
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
