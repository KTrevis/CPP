#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac == 1) {
		std::cerr << av[0] << " [number list]" << std::endl;
		return 1;
	}
	static_cast<void>(ac);
	std::string input = "";
	PmergeMe	merge;

	for (size_t i = 1; av[i]; i++) {
		input += av[i];
		input += " ";
	}
	if (input.find_first_not_of("0123456789 ") != std::string::npos) {
		std::cerr << "error: invalid character found" << std::endl;
		return 1;
	}
	merge.mergeInsertionSort(input);
}
