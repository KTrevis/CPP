#ifndef _FragTrap_HPP_
#define _FragTrap_HPP_

#include "ClapTrap.hpp"
#include <iostream>

class	FragTrap: public ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const &obj);
		~FragTrap();
		FragTrap &operator=(const FragTrap &obj);
		void	highFiveGuys();

	private:
};

#endif
