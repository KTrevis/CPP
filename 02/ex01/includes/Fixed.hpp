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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		Fixed			&operator=(Fixed const &ref);

	private:
		int					_getDecimalPart() const;
		int					_getFractionalPart() const;
		int					_value;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &ref);

#endif
