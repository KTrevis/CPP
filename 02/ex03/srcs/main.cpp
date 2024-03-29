/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:49:07 by ketrevis          #+#    #+#             */
/*   Updated: 2024/03/29 14:57:24 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	if (point == a || point == b || point == c)
		return false;
	return true;
}

int main() {
	Point		points[3];
	std::string	str;

	for (int i = 0; i < 3; i++) {
		std::cout << "Position x of the point " << i << " of the triangle" << std::endl;
		std::getline(std::cin, str);
		float x = std::stof(str.c_str());

		std::cout << "Position y of the point " << i << " of the triangle" << std::endl;
		std::getline(std::cin, str);
		float y = std::stof(str.c_str());
		points[i] = Point(x, y);
	}
}
