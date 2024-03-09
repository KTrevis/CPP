#include <iostream>

void	strToUpper(std::string &str) {
	for (unsigned long i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int	main(int ac, char **av) {
	std::string str;

	for (int i = 1; av[i]; i++) {
		str = av[i];
		strToUpper(str);
		std::cout << str << " ";
	}
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
