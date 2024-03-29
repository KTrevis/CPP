#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(float x, float y);
		Point(Point const &ref);
		~Point();
		Point	&operator=(Point const &ref);
		Fixed const	&getX() const;
		Fixed const	&getY() const;
		bool	operator==(Point const &ref) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream	&operator<<(std::ostream &os, Point const &ref);

#endif
