#ifndef _Intern_HPP_
#define _Intern_HPP_

#include "AForm.hpp"
#include <iostream>

#define FORMS_QUANTITY 3

class Intern {
	public:
		Intern();
		Intern(Intern const &obj);
		~Intern();
		Intern &operator=(const Intern &obj);
		AForm	*makeForm(std::string name, std::string target);

	private:
		void	deleteUnusedForms(AForm *forms[], int indexToKeep);
};

#endif
