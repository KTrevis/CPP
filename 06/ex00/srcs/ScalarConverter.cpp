/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:29:30 by ketrevis          #+#    #+#             */
/*   Updated: 2024/08/21 17:09:30 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <climits>
#include "Data.hpp"

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

enum e_mask {
	OVERFLOW_CHAR = 1,
	OVERFLOW_INT = 2,
	OVERFLOW_FLOAT = 4,
	OVERFLOW_DOUBLE = 8,
};

void	ScalarConverter::convert(const std::string str) {
	Data data(str);
	long l = std::strtol(str.c_str(), NULL, 10);
	long double ld = std::atof(str.c_str());
	int mask = 0;

	switch (data.type) {
		case UNDEFINED: 
			std::cerr << "error" << std::endl;
			break;
		case CHAR: if (overflows<char>(l)) mask += OVERFLOW_CHAR;
		case INT: if (overflows<int>(l)) mask += OVERFLOW_INT;
		case FLOAT: if (overflows<float>(ld)) mask += OVERFLOW_FLOAT;
		case DOUBLE: if (overflows<double>(ld)) mask += OVERFLOW_DOUBLE;
	}
	if (mask & OVERFLOW_CHAR)
		std::cout << "char overflow" << std::endl;
	if (mask & OVERFLOW_INT)
		std::cout << "int overflow" << std::endl;
	if (mask & OVERFLOW_FLOAT)
		std::cout << "float overflow" << std::endl;
	if (mask & OVERFLOW_DOUBLE)
		std::cout << "double overflow" << std::endl;
}
