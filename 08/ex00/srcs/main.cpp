#include <list>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

template <typename T>
void	test() {
	T arr;
	typename T::iterator it;
	arr.push_back(12);
	arr.push_back(16);
	arr.push_back(8);

	try {	
		it = easyfind(arr, 12);
		std::cout << "FOUND " << *it << std::endl;

		it = easyfind(arr, 16);
		std::cout << "FOUND " << *it << std::endl;

		it = easyfind(arr, 8);
		std::cout << "FOUND " << *it << std::endl;

		it = easyfind(arr, 123);
		std::cout << "FOUND " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main() {
	std::cout << "VECTOR" << std::endl;
	test<std::vector<int> >();
	std::cout << std::endl;

	std::cout << "LIST" << std::endl;
	test<std::list<int> >();
	std::cout << std::endl;
}
