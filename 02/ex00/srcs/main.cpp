#include <iostream>
#include <ostream>
#include "Fixed.hpp"

int	main() {
	Fixed	a;

	a.setRawBits(123);
	std::cout << "a raw bits: " << a << std::endl;

	Fixed b;
	std::cout << "b raw bits: " << b << std::endl;

	b = a;
	std::cout << "b raw bits: " << a << std::endl;

	b = Fixed(a);
	std::cout << "b raw bits: " << a << std::endl;

	b.setRawBits(83);
	std::cout << "b raw bits: " << a << std::endl;
}
