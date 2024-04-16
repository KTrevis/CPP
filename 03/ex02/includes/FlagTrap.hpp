#ifndef _FlagTrap_HPP_
#define _FlagTrap_HPP_

#include <iostream>
#include "ClapTrap.hpp"

class	FlagTrap: public ClapTrap {
	public:
		FlagTrap();
		FlagTrap(std::string name);
		FlagTrap(ClapTrap const &obj);
		~FlagTrap();
		FlagTrap &operator=(const ClapTrap &obj);
		void	highFivesGuys();

	private:
};

#endif
