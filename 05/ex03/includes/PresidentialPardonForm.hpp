#ifndef _PresidentialPardonForm_HPP_
#define _PresidentialPardonForm_HPP_

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		void	executeBehaviour() const;
};

#endif
