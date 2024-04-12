/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:12:39 by ketrevis          #+#    #+#             */
/*   Updated: 2024/04/12 15:13:29 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main() {
	int quantity = 0;
	std::cout << "Enter the number of animals wished : ";
	std::cin >> quantity;
	if (quantity <= 0) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	Animal	*animals[quantity];
	for (int i = 0; i < quantity; i++) {
		if (i < quantity / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < quantity; i++)
		animals[i]->makeSound();

	for (int i = 0; i < quantity; i++)
		delete animals[i];
}
