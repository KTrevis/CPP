#include "BitcoinExchange.hpp"
#include <exception>

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << av[0] << " [input_file]" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange	btc;
		btc.convert(av[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
