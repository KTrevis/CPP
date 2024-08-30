/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:29:30 by ketrevis          #+#    #+#             */
/*   Updated: 2024/08/30 15:36:17 by ketrevis         ###   ########.fr       */
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

static int	overflowChecker(Data data, const std::string &str) {
	long l = std::strtol(str.c_str(), NULL, 10);
	long double ld = std::strtold(str.c_str(), NULL);
	if (data.type == CHAR && ScalarConverter::castWillOverflow<char>(l)) return true;
	else if (data.type == INT && ScalarConverter::castWillOverflow<int>(l)) return true;
	else if (data.type == FLOAT && ScalarConverter::castWillOverflow<float>(ld)) return true;
	else if (data.type == DOUBLE && ScalarConverter::castWillOverflow<double>(ld)) return true;
	return false;
}

static void	displayOriginalType(const Data &data) {
	std::cout << "Original type: ";
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

static void	displayTypes(char n) {
	Displayer::display(n);
	Displayer::display(static_cast<int>(n));
	Displayer::display(static_cast<float>(n));
	Displayer::display(static_cast<double>(n));
}

static void	displayTypes(int n) {
	Displayer::display(static_cast<char>(n));
	Displayer::display(n);
	Displayer::display(static_cast<float>(n));
	Displayer::display(static_cast<double>(n));
}

static void	displayTypes(float n) {
	Displayer::display(static_cast<char>(n));
	Displayer::display(static_cast<int>(n));
	Displayer::display(n);
	Displayer::display(static_cast<double>(n));
}

static void	displayTypes(double n) {
	Displayer::display(static_cast<char>(n));
	Displayer::display(static_cast<int>(n));
	Displayer::display(static_cast<float>(n));
	Displayer::display(n);
}

static bool	isLiteral(std::string str) {
	if (str == "nan" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	char sign = str[0];
	if (sign != '-' && sign != '+')
		return false;
	str.erase(0, 1); // once the sign is stocked, we can remove it from the string
	if (str == "inf" || str == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << sign << "inff" << std::endl;
		std::cout << "double: " << sign << "inf" << std::endl;
		return true;
	}
	return false;
}

void	ScalarConverter::convert(const std::string &str) {
	Data data(str);

	if 	(isLiteral(str))
		return ;
	if (overflowChecker(data, str)) {
		std::cout << "invalid input" << std::endl;
		return ;
	}
	displayOriginalType(data);
	switch (data.type) {
		case CHAR: displayTypes(str[0]); break;
		case INT: displayTypes(std::atoi(str.c_str())); break;
		case FLOAT: displayTypes(static_cast<float>(std::atof(str.c_str()))); break;
		case DOUBLE: displayTypes(std::strtod(str.c_str(), NULL)); break;
		case UNDEFINED: break;
	}
}
