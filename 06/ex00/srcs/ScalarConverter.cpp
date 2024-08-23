/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:29:30 by ketrevis          #+#    #+#             */
/*   Updated: 2024/08/23 13:41:23 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <climits>
#include "Displayer.hpp"
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



static int	overflowChecker(const std::string &str) {
	long l = std::strtol(str.c_str(), NULL, 10);
	long double ld = std::atof(str.c_str());
	int mask = 0;

	if (ScalarConverter::overflows<char>(l)) mask += OVERFLOW_CHAR;
	if (ScalarConverter::overflows<int>(l)) mask += OVERFLOW_INT;
	if (ScalarConverter::overflows<float>(ld)) mask += OVERFLOW_FLOAT;
	if (ScalarConverter::overflows<double>(ld)) mask += OVERFLOW_DOUBLE;
	return mask;	
}

static void	displayOriginalType(const Data &data) {
	std::cout << "Original type : ";
	switch (data.type) {
		case CHAR:
			std::cout << "char" << std::endl;
			break;
		case INT:
			std::cout << "int" << std::endl;
			break;
		case FLOAT:
			std::cout << "float" << std::endl;
			break;
		case DOUBLE:
			std::cout << "double" << std::endl;
			break;
		default:
			std::cout << "error" << std::endl;
			break;
	}
}

static void	displayFromChar(char n, int mask) {
	Displayer::display(n, mask);
	Displayer::display(static_cast<int>(n), mask);
	Displayer::display(static_cast<float>(n), mask);
	Displayer::display(static_cast<double>(n), mask);
}

static void	displayFromInt(int n, int mask) {
	Displayer::display(static_cast<char>(n), mask);
	Displayer::display(n, mask);
	Displayer::display(static_cast<float>(n), mask);
	Displayer::display(static_cast<double>(n), mask);
}

static void	displayFromFloat(float n, int mask) {
	Displayer::display(static_cast<char>(n), mask);
	Displayer::display(static_cast<int>(n), mask);
	Displayer::display(n, mask);
	Displayer::display(static_cast<double>(n), mask);
}

static void	displayFromDouble(double n, int mask) {
	Displayer::display(static_cast<char>(n), mask);
	Displayer::display(static_cast<int>(n), mask);
	Displayer::display(static_cast<float>(n), mask);
	Displayer::display(n, mask);
}

void	ScalarConverter::convert(const std::string &str) {
	Data data(str);
	int mask = 0;

	displayOriginalType(data);
	if (data.type != CHAR) // if the data type is char, we know an overflow cannot happen
		mask = overflowChecker(str);
	if (data.type == CHAR)
		displayFromChar(str[0], mask);
	else if (data.type == INT)
		displayFromInt(std::atoi(str.c_str()), mask);
	else if (data.type == FLOAT)
		displayFromFloat(std::atof(str.c_str()), mask);
	else if (data.type == DOUBLE)
		displayFromDouble(std::strtod(str.c_str(), NULL), mask);
}
