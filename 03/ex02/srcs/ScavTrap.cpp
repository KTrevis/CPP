#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap : Default Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap : Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj): ClapTrap(obj) {
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScavTrap	&ScavTrap::operator= (const ScavTrap &obj) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj) {
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}
