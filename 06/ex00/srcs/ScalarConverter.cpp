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

static bool	setValues
	(const std::string &str, char &c, int &n, float &f, double &d) {
	switch (getType(str)) {
		case UNDEFINED:
			return false;
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
			n = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = strtod(str.c_str(), NULL);
			c = static_cast<char>(d);
			n = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
	}
	return true;
}

static void displayChar(const char &c, const double &d) {
	std::cout << "char: ";
	if (d > CHAR_MAX || !isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

static void displayInt(const int &n, const double &d) {
	std::cout << "int: ";
	if (d > INT_MAX)
		std::cout << "Overflow occured" << std::endl;
	else
		std::cout << n << std::endl;
}

static void displayFloat(const float &f, const double &d) {
	std::cout << "float: ";
	if (d > MAXFLOAT)
		std::cout << "Overflow occured" << std::endl;
	else {
		std::cout << f;
		if (static_cast<int>(f - static_cast<int>(f) == 0)) // if fractional part is 0
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void displayDouble(const double &d) {
	std::cout << "double: ";
	std::cout << d;
	if (static_cast<int>(d - static_cast<int>(d) == 0)) // if fractional part is 0
		std::cout << ".0";
	std::cout << std::endl;
}

static void	displayValues
	(const char &c, const int &n, const float &f, const double &d) {
	displayChar(c, d);
	displayInt(n, d);
	displayFloat(f, d);
	displayDouble(d);
}

void	displayLiteral(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan" || str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str == "+inf" || str == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

bool	isLiteral(const std::string &str) {
	std::string	literals[] = {
		"-inf",
		"+inf",
		"nan",
		"-inff",
		"+inff",
		"nanf",
	};

	for (int i = 0; i < 6; i++) {
		if (literals[i] == str) {
			displayLiteral(str);
			return true;
		}
	}
	return false;
}


void	ScalarConverter::convert(const std::string str) {
	char	c = 0;
	int		n = 0;
	float	f = 0;
	double	d = 0;

	if (isLiteral(str))
		return;
	if (!setValues(str, c, n, f, d)) {
		std::cerr << "FORMAT ERROR" << std::endl;
		return;
	}
	displayValues(c, n, f, d);
}
