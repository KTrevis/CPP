#ifndef _Cure_HPP_
#define _Cure_HPP_

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria {
	public:
		Cure();
		Cure(Cure const &obj);
		~Cure();
		Cure &operator=(const Cure &obj);
		void	use(ICharacter &target);
		AMateria	*clone() const;
};

#endif
