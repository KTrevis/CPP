#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int	main() {
	MutantStack<int> stack;
	stack.push(123);
	stack.push(12);
	std::cout << "LAST ELEMENT" << std::endl;
	std::cout << *(stack.end() - 1) << std::endl;
	std::cout << "FIRST ELEMENT" << std::endl;
	std::cout << *(stack.begin()) << std::endl;
	std::vector<int> arr;
	arr.push_back(123);
	arr.push_back(131);
	arr.push_back(85);
	stack.addNumbers(arr.begin(), arr.end());
	std::cout << "FULL LIST" << std::endl;
	for (MutantStack<int>::iterator it = stack.begin();
		it != stack.end(); it++) {
		std::cout << *it << std::endl;
	}
}
