#pragma once

#include <algorithm>
#include <exception>

class NotFound: public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Not found.";
		}
};

template<typename T>
void	easyfind(T container, int toFind) {
	if (std::find(container.begin(), container.end(), toFind) == container.end())
		throw NotFound();
}
