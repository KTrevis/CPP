#ifndef _RobotomyRequestForm_HPP_
#define _RobotomyRequestForm_HPP_

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		void	executeBehaviour() const;

	private:
		std::string	_target;
};

#endif
