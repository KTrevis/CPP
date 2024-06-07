#include "ScalarConverter.hpp"

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

e_type	getNumberType(std::string str) {
	int		dots = 0;
	size_t	i = 1;

	if (str[0] == '.' || !str[0])
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

e_type	getType(std::string str) {
	e_type type = getNumberType(str);
	if (type != UNDEFINED)
		return type;
	if (str.length() != 1)
		return UNDEFINED;
	if (str[0] >= ' ' && str[0] < 127)
		return CHAR;
	return UNDEFINED;
}

void	ScalarConverter::convert(std::string str) {
	char	c = 0;
	int		n = 0;
	float	f = 0;
	double	d = 0;
	switch (getType(str)) {
		case UNDEFINED:
			return;
		case CHAR:
			return;
		case INT:
			return;
		case FLOAT:
			return;
		case DOUBLE:
			return;
	}
}
