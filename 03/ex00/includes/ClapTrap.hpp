#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define uint unsigned int

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
		std::string	getName()	const;
		uint		getHP()		const;
		uint		getEnergy()	const;
		uint		getDamage()	const;

	private:
		std::string	_name;
		uint		_hp;
		uint		_energy;
		uint		_damage;
};

#endif
