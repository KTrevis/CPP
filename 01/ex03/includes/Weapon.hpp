#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {
	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		std::string const	&getType();
		void				setType(std::string newType);
		
	private:
		std::string	_type;
};

#endif
