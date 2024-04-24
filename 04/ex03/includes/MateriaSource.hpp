#ifndef _MateriaSource_HPP_
#define _MateriaSource_HPP_

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define SOURCE_MAX_MATERIAS 4

class MateriaSource: public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &obj);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &obj);
		void		learnMateria(AMateria *materia);
		AMateria	*createMateria(std::string const &type);
		void		useEveryMaterias(ICharacter &target);

	private:
		AMateria	*materias[4];
};

#endif
