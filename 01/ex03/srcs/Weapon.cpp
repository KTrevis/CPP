#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

Weapon::Weapon() {
	this->setType("");
}

Weapon::~Weapon() {}

std::string const	&Weapon::getType() {
	return this->_type;
}


void	Weapon::setType(std::string newType) {
	this->_type = newType;
}
