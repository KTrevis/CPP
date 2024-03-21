#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &ref);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed			&operator=(Fixed const &ref);

	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &ref);

#endif
