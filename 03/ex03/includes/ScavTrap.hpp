#ifndef _ScavTrap_HPP_
#define _ScavTrap_HPP_

#include "ClapTrap.hpp"
#include <iostream>

class	ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &obj);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &obj);
		void	guardGate();

	private:
};

#endif
