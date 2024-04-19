#ifndef _Character_HPP_
#define _Character_HPP_

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

#define CHARACTER_MAX_MATERIAS 4

class Character: public ICharacter {
	public:
		Character();
		Character(std::string name);
		Character(Character const &obj);
		~Character();
		Character &operator=(const Character &obj);
		std::string const	&getName() const;
		void	equip(AMateria *materia);
		void	unequip(int index);
		void	use(int index, ICharacter &target);

	private:
		AMateria	*materias[CHARACTER_MAX_MATERIAS];
		std::string name;
};

#endif
