#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) {
	this->setName(name);
}

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(ScavTrap const &ref) {
	*this = ref;
}

ScavTrap::~ScavTrap() {}

void	guardGate() {}
