#pragma once

#include <algorithm>
#include <exception>

class NotFound: public std::exception {
	public:
		virtual const char *what() const throw();
};

template<typename T>
typename T::iterator	easyfind(T &container, int toFind) {
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw NotFound();
	return it;
}
