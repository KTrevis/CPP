#ifndef _ScalarConverter_HPP_
#define _ScalarConverter_HPP_

#include <iostream>
#include <limits>

enum e_mask {
	OVERFLOW_CHAR = 1,
	OVERFLOW_INT = 2,
	OVERFLOW_FLOAT = 4,
	OVERFLOW_DOUBLE = 8,
};

class ScalarConverter {
	public:
	ScalarConverter(ScalarConverter const &obj);
	~ScalarConverter();
	ScalarConverter	&operator=(const ScalarConverter &obj);
	static void		convert(const std::string &str);

	template<typename Target, typename Original>
	static bool overflows(Original f) {
		Target max = std::numeric_limits<Target>::max();
		Target min;

		if (std::numeric_limits<Target>::is_iec559) // if f is a float we do that because min returns the lowest positive number 
			min = -std::numeric_limits<Target>::max(); // for the float and the double instead of the minimum value
		else
			min = std::numeric_limits<Target>::min();
		return (f < min || f > max);
	}
	protected:
	ScalarConverter();
};

#endif
