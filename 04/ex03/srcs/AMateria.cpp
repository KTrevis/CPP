#include "AMateria.hpp"
#include "MateriaSource.hpp"

AMateria::AMateria(const std::string &type): type(type) {}

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria const &obj) {
	if (this != &obj)
		*this = obj;
}

AMateria	&AMateria::operator= (const AMateria &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

std::string const	&AMateria::getType() const {
	return this->type;
}
