#include "whatever.hpp"
#include <iostream>

void	intTest() {
	int	a = 10;
	int	b = 10;
	std::cout << (int)(&b == &max(a, b)) << std::endl;
	std::cout << (int)(&b == &min(a, b)) << std::endl;
	b = 9;
	std::cout << (int)(&a == &max(a, b)) << std::endl;
	std::cout << (int)(&b == &min(a, b)) << std::endl;
	a = 8;
	std::cout << (int)(&b == &max(a, b)) << std::endl;
	std::cout << (int)(&a == &min(a, b)) << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
}

void	floatTest() {
	float	a = 10;
	float	b = 10;
	std::cout << (int)(&b == &max(a, b)) << std::endl;
	std::cout << (int)(&b == &min(a, b)) << std::endl;
	b = 9;
	std::cout << (int)(&a == &max(a, b)) << std::endl;
	std::cout << (int)(&b == &min(a, b)) << std::endl;
	a = 8;
	std::cout << (int)(&b == &max(a, b)) << std::endl;
	std::cout << (int)(&a == &min(a, b)) << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
}

void	stringTest() {
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int	main() {
	intTest();
	stringTest();
}
