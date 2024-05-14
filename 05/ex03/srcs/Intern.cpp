#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &obj) {
	if (this != &obj)
		*this = obj;
}

Intern	&Intern::operator=(const Intern &obj) {
	if (this == &obj)
		return *this;
	return *this;
}
