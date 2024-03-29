#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	if (point == a || point == b || point == c)
		return false;
	return true;
}
