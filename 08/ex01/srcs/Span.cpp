#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int size) {
	this->_maxSize = size;
}

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

int	Span::shortestSpan() {
	if (this->_arr.size() <= 1)
		throw NoSpanException();
	const std::vector<int> &arr = this->_arr;
	std::sort(arr.begin(), arr.end());
	int min = arr[1] - arr[0];

	for (unsigned int i = 1; i < arr.size(); i++) {
		if (arr[i] - arr[i - 1] < min)
			min = arr[i] - arr[i - 1];
	}

	return min;
}

int	Span::longestSpan() {
	if (this->_arr.size() <= 1)
		throw NoSpanException();
	const std::vector<int> &arr = this->_arr;
	std::sort(arr.begin(), arr.end());

	return arr[arr.size() - 1] - arr[0];
}

void	Span::addNumber(int n) {
	if (this->_arr.size() == this->_maxSize)
		return;
	this->_arr.push_back(n);
}

const char *Span::SpanFullException::what() const throw() {
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "No span found";
}
