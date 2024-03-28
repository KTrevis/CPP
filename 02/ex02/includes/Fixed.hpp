#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &ref);
		Fixed(int const n);
		Fixed(float const n);
		~Fixed();

		/* FUNCTIONS */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
		Fixed	&min(Fixed const &a, Fixed const &b);
		Fixed	&max(Fixed const &a, Fixed const &b);

		/* COMPARISON OPERATORS */
		bool	operator<(Fixed const &ref) const;
		bool	operator>(Fixed const &ref) const;
		bool	operator<=(Fixed const &ref) const;
		bool	operator>=(Fixed const &ref) const;
		bool	operator==(Fixed const &ref) const;
		bool	operator!=(Fixed const &ref) const;

		/* ARITHMETIC OPERATORS */
		Fixed	operator+(Fixed const &ref);
		Fixed	operator-(Fixed const &ref);
		Fixed	operator*(Fixed const &ref);
		Fixed	operator/(Fixed const &ref);

		/* INCREMENT OPERATORS */
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		Fixed	&operator=(Fixed const &ref);

	private:
		int					_getDecimalPart() const;
		int					_getFractionalPart() const;
		int					_value;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &ref);

#endif
