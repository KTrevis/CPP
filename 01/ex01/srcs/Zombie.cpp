#include "Zombie.hpp"
#include <iostream>
#include <ostream>

Zombie::Zombie(std::string name): _name(name) {}

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << this->_name << " deleted" << std::endl;
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}
