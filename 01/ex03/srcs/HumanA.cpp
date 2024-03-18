#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack() {
	if (!this->_weapon || this->_weapon->getType() == "")
		std::cout << this->_name << " attacks without weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &newWeapon) {
	this->_weapon = newWeapon;
}
