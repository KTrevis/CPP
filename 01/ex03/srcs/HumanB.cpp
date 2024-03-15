#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB() {};

void	HumanB::attack() {
	if (!this->_weapon || this->_weapon->getType() == "")
		std::cout << this->_name << " attacks without weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon) {
	this->_weapon = &newWeapon;
}
