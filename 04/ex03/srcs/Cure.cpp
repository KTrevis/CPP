#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(Cure const &obj): AMateria(obj) {
	if (this != &obj)
		*this = obj;
}

Cure	&Cure::operator= (const Cure &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

AMateria	*Cure::clone() const {
	return new Cure;
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
