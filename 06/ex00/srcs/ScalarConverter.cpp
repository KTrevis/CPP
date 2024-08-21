#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &obj) {
	if (this != &obj)
		*this = obj;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

static e_type	getNumberType(const std::string &str) {
	int		dots = 0;
	size_t	i = 1;

	if (!isdigit(str[0]) || !str[0])
		return UNDEFINED;
	while (str[i]) {
		if (i == str.length() - 1 && dots == 1 && str[i] == 'f')
			return FLOAT;
		if (str[i] != '.' && !isdigit(str[i]))
			return UNDEFINED;
		if (str[i] == '.')
			dots++;
		i++;
	}
	if (dots == 1)
		return DOUBLE;
	if (dots == 0)
		return INT;
	return UNDEFINED;
}

static e_type	getType(const std::string &str) {
	e_type type = getNumberType(str);
	if (type == DOUBLE && str[str.length() - 1] == '.')
		return UNDEFINED;
	if (type != UNDEFINED)
		return type;
	if (str.length() == 1 && str[0] >= ' ' && str[0] < 127)
		return CHAR;
	return UNDEFINED;
}

void	ScalarConverter::convert(const std::string str) {
	getType(str);
	(void)str;
}
