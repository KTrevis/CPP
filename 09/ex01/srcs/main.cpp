#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << av[0] << " [RPN]" << std::endl;
		return 1;
	}
	RPN	rpn;
	rpn.calculate(av[1]);
}
