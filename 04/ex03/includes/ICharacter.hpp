#ifndef _ICharacter_HPP_
#define _ICharacter_HPP_

#include <iostream>

class	AMateria;

class ICharacter {
	public:
		virtual ~ICharacter() {};
		virtual std::string const	&getName() const = 0;
		virtual void	equip(AMateria *materia) = 0;
		virtual void	unequip(int index) = 0;
		virtual void	use(int index, ICharacter &target) = 0;
};

#endif
