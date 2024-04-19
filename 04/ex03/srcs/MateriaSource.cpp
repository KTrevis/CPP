#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < SOURCE_MAX_MATERIAS; i++)
		this->materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < SOURCE_MAX_MATERIAS; i++)
		delete this->materias[i];
}

MateriaSource::MateriaSource(MateriaSource const &obj) {
	if (this != &obj)
		*this = obj;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < SOURCE_MAX_MATERIAS; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = materia;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	if (type == "ice")
		return new Ice;
	if (type == "cure")
		return new Cure;
	return NULL;
}
