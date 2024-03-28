#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(Fixed const &ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = n;
	this->_value <<= this->_bits;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(n * (1 << this->_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return this->_value;
}

void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

Fixed &Fixed::operator=(Fixed const &ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = ref.getRawBits();
	return *this;
}

int Fixed::toInt() const {
	return this->_value >> this->_bits;
}

float Fixed::toFloat() const {
	return (float)this->_value / (1 << this->_bits);
}

std::ostream &operator<<(std::ostream &os, Fixed const &ref) {
	os << ref.toFloat();
	return os;
}
