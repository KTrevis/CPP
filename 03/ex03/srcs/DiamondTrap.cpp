#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name) {
	std::cout << "DiamondTrap : Default Constructor Called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap : Destructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj): ClapTrap(obj) {
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

DiamondTrap	&DiamondTrap::operator= (const DiamondTrap &obj) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj) {
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}
