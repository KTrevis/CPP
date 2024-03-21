#include <iostream>
#include <ostream>
#include "Fixed.hpp"

int	main() {
	Fixed	a;

	a.setRawBits(123);
	std::cout << "a value: " << a << std::endl;

	Fixed b = a;
	std::cout << "b value: " << b << std::endl;

	Fixed c;
	std::cout << "c value: " << c << std::endl;

	c = Fixed(a);
	std::cout << "c value: " << c << std::endl;

	c.setRawBits(809);
	std::cout << "c value: " << c << std::endl;
}
