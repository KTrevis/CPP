#ifndef _ScavTrap_HPP_
#define _ScavTrap_HPP_

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ClapTrap const &obj);
		~ScavTrap();
		ScavTrap &operator=(const ClapTrap &obj);
		void	guardGate();

	private:
};

#endif
