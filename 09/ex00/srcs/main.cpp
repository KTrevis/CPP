#include "BitcoinExchange.hpp"
#include <exception>

int	main() {
	try {
		BitcoinExchange	btc;
		btc.convert("input.txt");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
