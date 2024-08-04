#include "Span.hpp"

Span::Span() {
	std::cout << "Span : Default Constructor Called" << std::endl;
}

Span::~Span() {
	std::cout << "Span : Destructor Called" << std::endl;
}

Span::Span(Span const &obj) {
	std::cout << "Span : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Span	&Span::operator=(const Span &obj) {
	std::cout << "Span : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}
