#include "FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name): ClapTrap(name, 100, 100, 30) {
	std::cout << "FlagTrap : Default Constructor Called" << std::endl;
}

FlagTrap::FlagTrap(): ClapTrap("FlagTrap", 100, 100, 30) {
	std::cout << "FlagTrap : Default Constructor Called" << std::endl;
}

FlagTrap::~FlagTrap() {
	std::cout << "FlagTrap : Destructor Called" << std::endl;
}

FlagTrap::FlagTrap(FlagTrap const &obj) {
	std::cout << "FlagTrap : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FlagTrap	&FlagTrap::operator= (const FlagTrap &obj) {
	std::cout << "FlagTrap : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	this->setName(obj.getName());
	this->setHP(obj.getHP());
	this->setEnergy(obj.getEnergy());
	this->setDamage(obj.getDamage());
	return (*this);
}

void	FlagTrap::highFivesGuys() {
	std::cout << "HIGH FIVE GUYS !" << std::endl;
}
