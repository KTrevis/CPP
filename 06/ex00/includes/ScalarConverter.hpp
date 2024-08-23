#ifndef _ScalarConverter_HPP_
#define _ScalarConverter_HPP_

#include <iostream>
#include <limits>

class ScalarConverter {
	public:
	ScalarConverter(ScalarConverter const &obj);
	~ScalarConverter();
	ScalarConverter	&operator=(const ScalarConverter &obj);
	static void		convert(std::string str);
	template<typename Target, typename Original>
	static bool overflows(Original f) {
		return (f < std::numeric_limits<Target>::min() || f > std::numeric_limits<Target>::max());
	}
	protected:
	ScalarConverter();
};

#endif
