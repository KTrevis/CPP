#include "Harl.hpp"
#include <iostream>

int	main() {
	Harl	harl;

	std::cout << "DEBUG PROMPT" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl << "INFO PROMPT" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl << "WARNING PROMPT" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << "ERROR PROMPT" << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl << "NON EXISTING PROMPT" << std::endl;
	harl.complain("NON EXISTING");
}
