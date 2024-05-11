#ifndef _Bureaucrat_HPP_
#define _Bureaucrat_HPP_

#include <exception>
#include <iostream>

#define uchar unsigned char

class Bureaucrat {
	public:
		Bureaucrat(std::string name, unsigned char grade);
		Bureaucrat();
		Bureaucrat(Bureaucrat const &obj);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &obj);

		const std::string	getName() const;
		uchar				getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		class GradeTooHighException: public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char	*what() const throw();
		};

	private:
		const std::string	_name;
		uchar				_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b);

#endif
