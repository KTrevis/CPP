#include "Displayer.hpp"
#include "ScalarConverter.hpp"

Displayer::Displayer() {}

Displayer::~Displayer() {}

Displayer::Displayer(Displayer const &obj) {
	if (this != &obj)
		*this = obj;
}

Displayer	&Displayer::operator=(const Displayer &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	Displayer::display(char c, int mask) {
	if (mask & OVERFLOW_CHAR)
		std::cout << "char: overflow" << std::endl;
	else if (c >= ' ' && c < 127)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void	Displayer::display(int n, int mask) {
	if (mask & OVERFLOW_INT)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << n << std::endl;
}

void	Displayer::display(float f, int mask) {
	if (mask & OVERFLOW_FLOAT) {
		std::cout << "float: overflow" << std::endl;
		return ;
	}
	std::cout << "float: " << f;
	if (static_cast<int>(f) - f == 0) // if the fractional part is 0
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	Displayer::display(double d, int mask) {
	if (mask & OVERFLOW_DOUBLE) {
		std::cout << "double: overflow" << std::endl;
		return ;
	}
		std::cout << "double: " << d;
	if (static_cast<int>(d) - d == 0) // if the fractional part is 0
		std::cout << ".0";
	std::cout << std::endl;
}
