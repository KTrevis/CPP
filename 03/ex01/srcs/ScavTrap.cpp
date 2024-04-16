#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap : Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(): ClapTrap("ScavTrap", 100, 50, 20) {
	std::cout << "ScavTrap : Default Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap : Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(ClapTrap const &obj) {
	std::cout << "ScavTrap : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScavTrap	&ScavTrap::operator=(const ClapTrap &obj) {
	std::cout << "ScavTrap : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	this->setHP(obj.getHP());
	this->setEnergy(obj.getEnergy());
	this->setDamage(obj.getDamage());
	return (*this);
}

void	ScavTrap::guardGate() {
	std::cout << this->getName() << " is now in gate keeper mode." << std::endl;
}
