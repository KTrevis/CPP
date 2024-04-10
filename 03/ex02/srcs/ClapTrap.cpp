#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
	std::cout << "ClapTrap : String constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, uint hp, uint energy, uint damage) {
	this->_name = name;
	this->_hp = hp;
	this->_energy = energy;
	this->_damage = damage;
	std::cout << "ClapTrap : String constructor called" << std::endl;
}

ClapTrap::ClapTrap() {
	this->_name = "ClapTrap";
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
	std::cout << "ClapTrap : Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap : Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ref) {
	*this = ref;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &ref) {
	if (this == &ref)
		return *this;
	this->_name = ref._name;
	this->_damage = ref._damage;
	this->_energy = ref._energy;
	this->_hp = ref._hp;
	return *this;
}

void	ClapTrap::attack(std::string const &target) {
	if (this->_energy == 0) {
		std::cout << "ClapTrap " << this->_name << " out of energy." << std::endl; 
		return ;
	}
	this->_energy -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp == 0 || this->_hp < amount) {
		std::cout << "ClapTrap " << this->_name << " died." << std::endl;
		this->_hp = 0;
		return ;
	}
	this->_hp -= amount;
	std::cout << "ClapTrap " << this->_damage << " takes " << amount << " of damage." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy == 0) {
		std::cout << "ClapTrap " << this->_name << " out of energy." << std::endl; 
		return ;
	}
	this->_energy -= 1;
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name << " repairs for " << amount << " hp." << std::endl;
}

/* GETTERS */
std::string		ClapTrap::getName() const {
	return this->_name;
}

uint	ClapTrap::getHP() const {
	return this->_hp;
}

uint	ClapTrap::getEnergy() const {
	return this->_energy;
}

uint	ClapTrap::getDamage() const {
	return this->_damage;
}

/* SETTERS */
void	ClapTrap::setName(std::string name) {
	this->_name = name;
}

void	ClapTrap::setHP(uint hp) {
	this->_hp = hp;
}

void	ClapTrap::setEnergy(uint energy) {
	this->_energy = energy;
}

void	ClapTrap::setDamage(uint damage) {
	this->_damage = damage;
}
