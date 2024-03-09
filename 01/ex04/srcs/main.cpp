#include <string>
#include <fstream>
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Please enter 3 parameters" << std::endl;
		return (1);
	}
	// goal: copy fileInput in fileOutput while replacing every occurence of s1 by s2
	std::string		str = av[1];
	std::ifstream	fileInput(str.c_str());
	if (!fileInput) {
		std::cerr << str << " does not exist." << std::endl;
		return (1);
	}
	std::ofstream	fileOutput((str + ".replace").c_str());
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	while (std::getline(fileInput, str)) {
		size_t	index = str.find(s1);
		if (index != std::string::npos) {
			str.erase(index, s1.length());
			str.insert(index, s2);
		}
		fileOutput << str << std::endl;
	}
}
