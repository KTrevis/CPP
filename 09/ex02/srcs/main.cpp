#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	static_cast<void>(ac);
	std::string input = "";
	PmergeMe	merge;

	for (size_t i = 1; av[i]; i++) {
		input += av[i];
		input += " ";
	}
	merge.mergeInsertionSort(input);
}
