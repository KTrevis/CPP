#include <iostream>
#include "Fixed.hpp"

void	comparisonCheck(Fixed &a, Fixed &b) {
	std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << b << std::endl;
	if (a == b)
		std::cout << "a == b true" << std::endl;
	if (a != b)
		std::cout << "a != b true" << std::endl;
	if (a <= b)
		std::cout << "a <= b true" << std::endl;
	if (a >= b)
		std::cout << "a >= b true" << std::endl;
	if (a < b)
		std::cout << "a < b true" << std::endl;
	if (a > b)
		std::cout << "a > b true" << std::endl;
	std::cout << std::endl;
}

void	comparisonTester(Fixed &a, Fixed &b) {
	std::cout << "COMPARISON TEST" << std::endl;
	std::cout << "---------------" << std::endl;

	comparisonCheck(a, b);
	a = 123;
	comparisonCheck(a, b);
	b = 122;
	comparisonCheck(a, b);
}

void	arithmeticTester(Fixed &a) {
	std::cout << "ARITHMETIC TEST" << std::endl;
	std::cout << "---------------" << std::endl;

	std::cout << "before addition " << a << std::endl;
	a = a + 10;
	std::cout << "after addition " << a << std::endl;
	std::cout << std::endl;

	std::cout << "before substraction " << a << std::endl;
	a = a - 30;
	std::cout << "after substraction " << a << std::endl;
	std::cout << std::endl;

	std::cout << "before multiplication " << a << std::endl;
	a = a * 2;
	std::cout << "after multiplication " << a << std::endl;
	std::cout << std::endl;

	std::cout << "before division " << a << std::endl;
	a = a / 2;
	std::cout << "after division " << a << std::endl;
	std::cout << std::endl;
}

void	printABvalues(Fixed &a, Fixed &b) {
	std::cout << "b value " << b << std::endl;
	std::cout << "a value " << a << std::endl;
}

void	incrementTester(Fixed &a, Fixed &b) {
	std::cout << "INCREMENTER TEST" << std::endl;
	std::cout << "---------------" << std::endl;

	b = a;
	std::cout << "before post incrementing" << std::endl;
	printABvalues(a, b);
	b = a++;
	std::cout << "after post incrementing" << std::endl;
	printABvalues(a, b);
	std::cout << std::endl;

	std::cout << "before post decrementing" << std::endl;
	printABvalues(a, b);
	b = a--;
	std::cout << "after post decrementing" << std::endl;
	printABvalues(a, b);
	std::cout << std::endl;

	std::cout << "before pre incrementing" << std::endl;
	printABvalues(a, b);
	b = ++a;
	std::cout << "after pre incrementing" << std::endl;
	printABvalues(a, b);
	std::cout << std::endl;

	std::cout << "before pre decrementing" << std::endl;
	printABvalues(a, b);
	b = --a;
	std::cout << "after pre decrementing" << std::endl;
	printABvalues(a, b);
	std::cout << std::endl;
}

int main( void ) {
	Fixed a(123.34f);
	Fixed b(123.34f);

	comparisonTester(a, b);
	arithmeticTester(a);
	incrementTester(a, b);
}
