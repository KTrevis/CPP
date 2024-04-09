#ifndef _DiamondTrap_HPP_
#define _DiamondTrap_HPP_

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap: FragTrap, ScavTrap {
	public:
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &obj);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &obj);

	private:
		std::string	_name;
};

#endif
