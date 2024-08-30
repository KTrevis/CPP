#include <ScalarConverter.hpp>
#include <cstdio>
#include <cfloat>
#include <sstream>

int	main(int ac, char **av) {
	(void)ac;
	if (ac != 2) {
		std::cerr << "argument number invalid" << std::endl;
		return 1;
	}
		ScalarConverter::convert(av[1]);
}
