#include "Array.hpp"
#include <iostream>
#include <sstream>

int	main() {
	Array<std::string>	arr(100);

	for (unsigned int i = 0; i < arr.size(); i++) {
		std::stringstream	ss;
		ss << i;
		arr[i] = ss.str();
	}

	Array<std::string>	cpy = arr;

	try {
		std::cout << cpy[99] << std::endl;
		std::cout << arr[99] << std::endl;
		cpy[99] = "coucou";
		std::cout << cpy[99] << std::endl;
		std::cout << arr[99] << std::endl;
		arr = cpy;
		std::cout << arr[99] << std::endl;
		std::cout << cpy[100] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
