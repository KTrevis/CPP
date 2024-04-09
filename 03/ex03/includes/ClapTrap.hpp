#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#define uint unsigned int

class ClapTrap {
	public:
		ClapTrap(std::string name);
		ClapTrap(std::string name, uint hp, uint energy, uint damage);
		ClapTrap(ClapTrap const &ref);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &ref);
		void			attack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		/* GETTERS */
		unsigned int	getHP() const;
		unsigned int	getEnergy() const;
		std::string		getName() const;

	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_damage;
};

#endif
