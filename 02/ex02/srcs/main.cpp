#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;

	a = Fixed(123.34f);
	std::cout << a << std::endl;
}
