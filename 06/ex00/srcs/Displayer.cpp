#include "Displayer.hpp"
#include "ScalarConverter.hpp"
#include <cmath>

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

void	Displayer::display(char c) {
	if (c >= ' ' && c < 127)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void	Displayer::display(int n) {
	std::cout << "int: " << n << std::endl;
}

void	Displayer::display(float f) {
	std::cout << "float: " << f;
	if (static_cast<int>(f) - f == 0) // if the fractional part is 0
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	Displayer::display(double d) {
	std::cout << "double: " << d;
	if (static_cast<int>(d) - d == 0) // if the fractional part is 0
		std::cout << ".0";
	std::cout << std::endl;
}
