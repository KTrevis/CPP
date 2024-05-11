#ifndef _Form_HPP_
#define _Form_HPP_

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(std::string name, uchar requiredGrade);
		Form(Form const &obj);
		~Form();
		Form &operator=(const Form &obj);
		void		beSigned(Bureaucrat &b);
		uchar		getRequiredGrade() const;
		std::string	getName() const;
		bool		isSigned() const;

		class GradeTooLowException: public std::exception {
			virtual const char *what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char *what() const throw();
		};

	private:
		const std::string 	_name;
		bool				_isSigned;
		const uchar			_requiredGrade;
};

#endif
