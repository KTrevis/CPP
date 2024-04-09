#include "ScavTrap.hpp"

void	displayHP(ClapTrap &ref) {
	std::cout << ref.getName() << " HP: " << ref.getHP() << std::endl;
}

int	main() {
	ScavTrap bob("bob");

	bob.attack("michel");
	displayHP(bob);
	bob.takeDamage(11);
	displayHP(bob);
	bob.beRepaired(2);
	displayHP(bob);
	bob.attack("michel");
	bob.guardGate();
}
