#include "utils.hpp"
#include <iostream>
#include <cstdlib>

int	main(int ac, char **av) {
	(void)ac;
	if (ac != 3) {
		std::cout << "Enter a number, and the name of the zombies" << std::endl;
		return (1);
	}
	int		size = std::atoi(av[1]);
	Zombie*	zombies = zombieHorde(size, av[2]);
	for (int i = 0; i < size; i++)
		zombies->announce();
	delete [] zombies;
}
