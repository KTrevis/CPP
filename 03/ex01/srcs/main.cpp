#include "ScavTrap.hpp"

void	displayData(ClapTrap &ref) {
	std::cout << ref.getName() << " data:" << std::endl;
	std::cout << "HP: " << ref.getHP() << std::endl;
	std::cout << "Energy: " << ref.getEnergy() << std::endl;
	std::cout << "Damage: " << ref.getDamage() << std::endl;
}

int	main() {
	ScavTrap bob("bob");
	ClapTrap michel("michel");
	ScavTrap lucas("lucas");

	bob.attack("michel");
	displayData(bob);
	bob.takeDamage(11);
	displayData(bob);
	bob.beRepaired(2);
	displayData(bob);
	bob.attack("michel");
	bob.guardGate();
	michel = bob;
	displayData(michel);
	lucas = michel;
	displayData(lucas);
}
