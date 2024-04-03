#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	public:
		ClapTrap(std::string name);
		ClapTrap();
		ClapTrap(ClapTrap const &ref);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &ref);
		void			attack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		/* GETTERS */
		unsigned int	getHP();
		unsigned int	getEnergy();
		std::string		getName();
		void			setName(std::string name);

	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_damage;
};

#endif
