#include "Data.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>

Data::Data() {}

e_type	Data::getType(const std::string &str) {
	int		dots = 0;
	size_t	i = 1;

	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return CHAR;
	if (!str[0] || (str[0] != '-' && !isdigit(str[0])))
		return UNDEFINED;
	while (str[i]) {
		if (i == str.length() - 1 && dots == 1 && str[i] == 'f' && str[i - 1] != '.')
			return FLOAT;
		if (str[i] != '.' && !isdigit(str[i]))
			return UNDEFINED;
		if (str[i] == '.')
			dots++;
		i++;
	}
	if (dots == 1 && str[str.length() - 1] != '.')
		return DOUBLE;
	if (dots == 0)
		return INT;
	return UNDEFINED;
}

Data::Data(const std::string &str) {
	this->type = getType(str);
}

Data::~Data() {}

Data::Data(Data const &obj) {
	if (this != &obj)
		*this = obj;
}

Data	&Data::operator=(const Data &obj) {
	if (this == &obj)
		return *this;
	return *this;
}
