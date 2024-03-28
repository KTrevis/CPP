#include "Fixed.hpp"
#include <cmath>

/* CONSTRUCTORS */
Fixed::Fixed() {
	this->_value = 0;
}

Fixed::Fixed(Fixed const &ref) {
	*this = ref;
}

Fixed::Fixed(int const n) {
	this->_value = n;
	this->_value <<= this->_bits;
}

Fixed::Fixed(float const n) {
	this->_value = roundf(n * (1 << this->_bits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return this->_value;
}

void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

/* FUNCTIONS */
int Fixed::toInt() const {
	return this->_value >> this->_bits;
}

float Fixed::toFloat() const {
	return (float)this->_value / (1 << this->_bits);
}

Fixed &Fixed::operator=(Fixed const &ref) {
	this->_value = ref.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &os, Fixed const &ref) {
	os << ref.toFloat();
	return os;
}

Fixed const	&min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return b;
}

Fixed const	&max(Fixed const &a, Fixed const &b) {
	if (a < b)
		return b;
	return a;
}

/* COMPARISON OPERATORS */
bool Fixed::operator<(Fixed const &ref) const {
	return this->toFloat() < ref.toFloat();
}

bool Fixed::operator>(Fixed const &ref) const {
	return this->toFloat() > ref.toFloat();
}

bool Fixed::operator<=(Fixed const &ref) const {
	return this->toFloat() <= ref.toFloat();
}

bool Fixed::operator>=(Fixed const &ref) const {
	return this->toFloat() >= ref.toFloat();
}

bool Fixed::operator==(Fixed const &ref) const {
	return this->toFloat() == ref.toFloat();
}

bool Fixed::operator!=(Fixed const &ref) const {
	return this->toFloat() != ref.toFloat();
}

/* ARITHMETIC OPERATORS */
Fixed Fixed::operator+(Fixed const &ref) {
	return Fixed(this->toFloat() + ref.toFloat());
}

Fixed Fixed::operator-(Fixed const &ref) {
	return Fixed(this->toFloat() - ref.toFloat());
}

Fixed Fixed::operator*(Fixed const &ref) {
	return Fixed(this->toFloat() * ref.toFloat());
}

Fixed Fixed::operator/(Fixed const &ref) {
	return Fixed(this->toFloat() / ref.toFloat());
}

/* INCREMENT OPERATORS */
Fixed	&Fixed::operator++() {
	*this = *this + 1;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	*this = *this + 1;
	return temp;
}

Fixed	&Fixed::operator--() {
	*this = *this - 1;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	*this = *this - 1;
	return temp;
}
