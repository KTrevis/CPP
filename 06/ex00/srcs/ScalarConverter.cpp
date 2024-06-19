#include "ScalarConverter.hpp"
#include <cstdlib>

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

e_type	ScalarConverter::getNumberType(std::string str) {
	int		dots = 0;
	size_t	i = 1;

	if (!isdigit(str[i]) || !str[0])
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

e_type	ScalarConverter::getType(std::string str) {
	e_type type = getNumberType(str);
	if (type != UNDEFINED)
		return type;
	if (str.length() == 1 && str[0] >= ' ' && str[0] < 127)
		return CHAR;
	return UNDEFINED;
}

void	ScalarConverter::convert(std::string str) {
	char	c = 0;
	int		n = 0;
	float	f = 0;
	double	d = 0;

	std::cout << getType(str) << std::endl;
	switch (getType(str)) {
		case UNDEFINED:
			break;
		case CHAR:
			c = str[0];
			n = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INT:
			n = atoi(str.c_str());
			c = static_cast<char>(n);
			f = static_cast<float>(n);
			d = static_cast<double>(n);
			break;
		case FLOAT:
			f = atof(str.c_str());
			c = static_cast<char>(f);
			f = static_cast<float>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = strtod(str.c_str(), NULL);
			c = static_cast<char>(d);
			n = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
	}
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " <<  f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
