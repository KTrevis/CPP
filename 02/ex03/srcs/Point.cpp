#include "Point.hpp"

Point::Point() {}

Point::Point(float x, float y): _x(x), _y(y) {}

Point::Point(Point const &ref) {
	*this = ref;
}

Point::~Point() {}


Fixed const	&Point::getX() const {
	return this->_x;
}

Fixed const	&Point::getY() const {
	return this->_y;
}

Point	&Point::operator=(Point const &ref) {
	(void)ref;
	return *this;
}

bool	Point::operator==(Point const &ref) const {
	return (this->_x == ref._x && this->_y == ref._y);
}

std::ostream	&operator<<(std::ostream &os, Point const &ref) {
	os << "x: " << ref.getX() << " y: " << ref.getY();
	return os;
}
