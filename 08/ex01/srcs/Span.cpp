#include "Span.hpp"

Span::Span(int size) {}

Span::Span() {}

Span::~Span() {}

Span::Span(Span const &obj) {
	if (this != &obj)
		*this = obj;
}

Span	&Span::operator=(const Span &obj) {
	if (this == &obj)
		return *this;
	return *this;
}

void	Span::addNumber(int n) {
	this->_arr.push_back(n);
	for (std::vector<int>::iterator it = this->_arr.begin(); it != this->_arr.end(); it++)
		std::cout << *it << std::endl;
}
