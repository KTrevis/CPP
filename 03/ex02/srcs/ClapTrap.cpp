#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hp = 10;
	this->_energy = 10;
	this->_damage = 0;
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
	std::cout << "ClapTrap : Copy constructor called" << std::endl;
	*this = ref;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &ref) {
	std::cout << "ClapTrap : Copy operator called" << std::endl;
	if (this == &ref)
		return *this;
	this->_damage = ref._damage;
	this->_energy = ref._energy;
	this->_hp = ref._hp;
	return *this;
}

void	ClapTrap::attack(std::string const &target) {
	if (!this->canAct())
		return ;
	this->_energy -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " of damage." << std::endl;
	if (this->_hp == 0 || this->_hp < amount) {
		this->_hp = 0;
		return ;
	}
	this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->canAct())
		return ;
	this->_energy -= 1;
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name << " repairs for " << amount << " hp." << std::endl;
}

std::string		ClapTrap::getName() const {
	return this->_name;
}

bool	ClapTrap::canAct() {
	if (this->_hp == 0) {
		std::cout << this->_name << " cannot act, it is out of hit points." << std::endl;
		return false;
	}
	if (this->_energy == 0) {
		std::cout << this->_name << " cannot act, it is out of energy." << std::endl;
		return false;
	}
	return true;
}

/* GETTERS */
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

void	ClapTrap::setHP(uint HP) {
	this->_hp = HP;
}

void	ClapTrap::setEnergy(uint energy) {
	this->_energy = energy;
}

void	ClapTrap::setDamage(uint damage) {
	this->_damage = damage;
}
