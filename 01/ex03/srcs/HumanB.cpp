#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name) {}

HumanB::~HumanB() {};

void	HumanB::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon) {
	this->_weapon = &newWeapon;
}
