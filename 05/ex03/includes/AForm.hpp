#ifndef _Form_HPP_
#define _Form_HPP_

#include <exception>
#include "Bureaucrat.hpp"

class AForm {
	public:
		AForm(AForm const &obj);
		~AForm();
		AForm &operator=(const AForm &obj);
		void		beSigned(Bureaucrat &b);
		uchar		getSignGrade() const;
		uchar		getExecGrade() const;
		std::string	getName() const;
		bool		isSigned() const;
		void		execute(Bureaucrat const &executor) const;
		virtual void	executeBehaviour() const = 0;

		class GradeTooLowException: public std::exception {
			virtual const char *what() const throw();
		};

		class GradeTooHighException: public std::exception {
			virtual const char *what() const throw();
		};

	protected:
		AForm();
		AForm(std::string name, uchar requiredGrade, uchar _execGrade);

	private:
		const std::string 	_name;
		bool				_isSigned;
		const uchar			_signGrade;
		const uchar			_execGrade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &b);

#endif
