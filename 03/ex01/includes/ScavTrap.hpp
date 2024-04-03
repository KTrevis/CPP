#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap();
		ScavTrap(ScavTrap const &ref);
		~ScavTrap();
		ClapTrap &operator=(ClapTrap const &ref);
		void	guardGate();
};

#endif
