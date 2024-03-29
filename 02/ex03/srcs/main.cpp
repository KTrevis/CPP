/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:49:07 by ketrevis          #+#    #+#             */
/*   Updated: 2024/03/29 17:36:56 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point	*trianglePoints[4];
	float x, y;

	for (int i = 0; i < 3; i++) {
		std::cout << "Input x position of the point " << i << " of the triangle" << std::endl;
		std::cin >> x;
	
		std::cout << "Input y position of the point " << i << " of the triangle" << std::endl;
		std::cin >> y;
		trianglePoints[i] = new Point(x, y);
	}
	std::cout << "Input x position your point" << std::endl;
	std::cin >> x;
	
	std::cout << "Input y position of your point"  << std::endl;
	std::cin >> y;

	trianglePoints[3] = new Point(x, y);
	bsp(*trianglePoints[0], *trianglePoints[1], *trianglePoints[2], *trianglePoints[3]);
	for (int i = 0; i < 4; i++) 
		delete trianglePoints[i];
}
