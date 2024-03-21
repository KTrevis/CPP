#include "Fixed.hpp"

Fixed::Fixed() {
	this->_value = 0;
}

Fixed::Fixed(Fixed const &ref) {
	*this = ref;
}

Fixed::Fixed(int const n) {
	this->setRawBits(n);
}

Fixed::Fixed(float const n) {
	this->setRawBits(n);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return this->_value;
}

void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

Fixed &Fixed::operator=(Fixed const &ref) {
	this->_value = ref.getRawBits();
	return *this;
}

int Fixed::toInt() const {
	return this->_value;
}

float Fixed::toFloat() const {
	return (float)this->_value / (1 << this->_bits);
}

std::ostream &operator<<(std::ostream &os, Fixed const &ref) {
	os << ref.toFloat();
	return os;
}
