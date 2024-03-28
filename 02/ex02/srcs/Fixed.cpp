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
	this->setRawBits(n);
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = n * (1 << this->_bits);
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


int Fixed::toInt() const {
	return this->_value >> this->_bits;
}

float Fixed::toFloat() const {
	return roundf((float)this->_value / (1 << this->_bits));
}

// comparison operators
bool Fixed::operator<(Fixed const &ref) {
	return this->toFloat() < ref.toFloat();
}

bool Fixed::operator>(Fixed const &ref) {
	return this->toFloat() > ref.toFloat();
}

bool Fixed::operator<=(Fixed const &ref) {
	return this->toFloat() <= ref.toFloat();
}

bool Fixed::operator>=(Fixed const &ref) {
	return this->toFloat() >= ref.toFloat();
}

bool Fixed::operator==(Fixed const &ref) {
	return this->toFloat() == ref.toFloat();
}

bool Fixed::operator!=(Fixed const &ref) {
	return this->toFloat() != ref.toFloat();
}

Fixed &Fixed::operator=(Fixed const &ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = ref.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &os, Fixed const &ref) {
	os << ref.toFloat();
	return os;
}
