#ifndef _Ice_HPP_
#define _Ice_HPP_

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria {
	public:
		Ice();
		Ice(Ice const &obj);
		~Ice();
		Ice &operator=(const Ice &obj);
		void		use(ICharacter &target);
		AMateria	*clone() const;
};

#endif
