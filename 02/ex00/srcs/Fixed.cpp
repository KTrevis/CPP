#include "Fixed.hpp"

Fixed::Fixed() {
	this->_value = 0;
}

Fixed::Fixed(Fixed const &ref) {
	*this = ref;
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

std::ostream	&operator<<(std::ostream &os, Fixed const &ref) {
	os << ref.getRawBits();
	return os;
}
