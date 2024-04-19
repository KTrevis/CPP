#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(): AMateria("type") {}

Ice::~Ice() {}

Ice::Ice(Ice const &obj): AMateria(obj) {
	if (this != &obj)
		*this = obj;
}

Ice	&Ice::operator= (const Ice &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone() const {
	return new Ice;
}
