#include "FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name): ClapTrap(name) {
	std::cout << "FlagTrap : String Constructor Called" << std::endl;
	this->setHP(100);
	this->setEnergy(100);
	this->setDamage(30);
}

FlagTrap::FlagTrap(): ClapTrap("FlagTrap") {
	std::cout << "FlagTrap : Default Constructor Called" << std::endl;
	this->setHP(100);
	this->setEnergy(100);
	this->setDamage(30);
}

FlagTrap::~FlagTrap() {
	std::cout << "FlagTrap : Destructor Called" << std::endl;
}

FlagTrap::FlagTrap(ClapTrap const &obj) {
	std::cout << "FlagTrap : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FlagTrap	&FlagTrap::operator=(const ClapTrap &obj) {
	std::cout << "FlagTrap : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	this->setHP(obj.getHP());
	this->setEnergy(obj.getEnergy());
	this->setDamage(obj.getDamage());
	return (*this);
}

void	FlagTrap::highFivesGuys() {
	std::cout << "HIGH FIVE GUYS !" << std::endl;
}
