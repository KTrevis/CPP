#include <string>
#include <iostream>

int	main() {
	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string		&stringREF = str;

	std::cout << "str address:\t\t" << &str << std::endl;
	std::cout << "stringPTR held address:\t" << stringPTR << std::endl;
	std::cout << "stringREF held address:\t" << &stringREF << std::endl;

	std::cout << "str value:\t\t" << str << std::endl;
	std::cout << "stringPTR value:\t" << *stringPTR << std::endl;
	std::cout << "stringREF value:\t" << stringREF << std::endl;
}
