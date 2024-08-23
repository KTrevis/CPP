#include <ScalarConverter.hpp>
#include <cstdio>
#include <cfloat>
#include <sstream>

int	main(int ac, char **av) {
	(void)ac;
	if (av[1])
		ScalarConverter::convert(av[1]);
}
