#include "ScavTrap.hpp"

void	displayData(ClapTrap &ref) {
	std::cout << std::endl;
	std::cout << ref.getName() << " data:" << std::endl;
	std::cout << "HP: " << ref.getHP() << std::endl;
	std::cout << "Energy: " << ref.getEnergy() << std::endl;
	std::cout << "Damage: " << ref.getDamage() << std::endl;
	std::cout << std::endl;
}

int	main() {
	ScavTrap bob("bob");
	ClapTrap michel("michel");

	displayData(bob);
	bob.guardGate();
	bob.attack("michel");
	displayData(bob);

	displayData(michel);
	michel.takeDamage(bob.getDamage());
	displayData(michel);

	michel.beRepaired(2);
	displayData(michel);

	michel.takeDamage(1);
	displayData(michel);

	michel = bob;
	displayData(michel);

	while (bob.getEnergy() != 0)
		bob.beRepaired(1);
	displayData(bob);
	bob.beRepaired(1);
	displayData(bob);
}
