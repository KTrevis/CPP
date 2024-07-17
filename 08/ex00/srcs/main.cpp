#include <list>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

void	listTest() {
	std::cout << "LIST TEST" << std::endl;
	std::list<int>	arr;
	arr.push_back(12);
	arr.push_back(16);
	arr.push_back(8);
	try {
		int toFind;
		toFind = 12;
		easyfind(arr, toFind);
		std::cout << "FOUND " << toFind << std::endl;
		toFind = 16;
		easyfind(arr, toFind);
		std::cout << "FOUND " << toFind << std::endl;
		toFind = 8;
		easyfind(arr, toFind);
		std::cout << "FOUND " << toFind << std::endl;
		toFind = 20;
		easyfind(arr, toFind);
		std::cout << "FOUND " << toFind << std::endl;
	} catch (std::exception &e) {
		std::cout << "NOT FOUND" << std::endl;
	}
}

void	vectorTest() {
	std::cout << "VECTOR TEST" << std::endl;
	std::vector<int>	arr;
	arr.push_back(12);
	arr.push_back(16);
	arr.push_back(8);
	try {
		int toFind;
		toFind = 12;
		easyfind(arr, toFind);
		std::cout << "FOUND " << toFind << std::endl;
		toFind = 16;
		easyfind(arr, toFind);
		std::cout << "FOUND " << toFind << std::endl;
		toFind = 8;
		easyfind(arr, toFind);
		std::cout << "FOUND " << toFind << std::endl;
		toFind = 20;
		easyfind(arr, toFind);
		std::cout << "FOUND " << toFind << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what();
	}
}

int	main() {
	vectorTest();
	listTest();
}
