#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap() {}

ClapTrap::~ClapTrap() {}

ClapTrap::ClapTrap(ClapTrap const &ref) {
	*this = ref;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &ref) {
	this->_name = ref._name;
	this->_damage = ref._damage;
	this->_energy = ref._energy;
	this->_hp = ref._hp;
	return *this;
}

void	ClapTrap::attack(std::string const &target) {
	this->_energy -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_energy -= 1;
	std::cout << "ClapTrap " << this->_damage << " takes " << amount << " of damage." << std::endl;
	this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	this->_energy -= 1;
	std::cout << "ClapTrap " << this->_name << " repairs for " << amount << " hp." << std::endl;
	this->_hp += amount;
}

unsigned int	ClapTrap::getHP() {
	return this->_hp;
}

unsigned int	ClapTrap::getEnergy() {
	return this->_energy;
}

std::string		ClapTrap::getName() {
	return this->_name;
}
