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
		return (f < -std::numeric_limits<Target>::max() || f > std::numeric_limits<Target>::max());
	}
	protected:
	ScalarConverter();
};

#endif
