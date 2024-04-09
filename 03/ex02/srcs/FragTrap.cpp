#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap : Default Constructor Called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap : Destructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj): ClapTrap(obj) {
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FragTrap	&FragTrap::operator= (const FragTrap &obj) {
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &obj) {
		//	this->attributes = obj.attributes;
		//	...
	}
	return (*this);
}

void	FragTrap::highFiveGuys() {
	std::cout << "HIGH FIVE !" << std::endl;
}

