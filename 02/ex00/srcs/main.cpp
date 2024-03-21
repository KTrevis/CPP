#include <iostream>
#include <ostream>
#include "Fixed.hpp"

int	main() {
	Fixed	a;

	a.setRawBits(123);
	std::cout << "a value: " << a << std::endl;

	Fixed b;
	std::cout << "b value: " << b << std::endl;

	b = a;
	std::cout << "a value: " << a << std::endl;

	b = Fixed(a);
	std::cout << "a value: " << a << std::endl;

	b.setRawBits(89);
	std::cout << "a value: " << a << std::endl;
}
