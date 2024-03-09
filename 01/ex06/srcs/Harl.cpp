#include "Harl.hpp"
#include <iostream>

Harl::Harl() {};

Harl::~Harl() {};

int	Harl::strToIndex(std::string str) {
	std::string	levels[4];

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	for (int i = 0; i < 4; i++) {
		if (levels[i] == str)
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level) {
	void	(Harl::*f[4])();

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;

	int index = strToIndex(level);
	if (index == -1) {
		std::cerr << "Invalid comment level." << std::endl;
		return ;
	}
	while (index < 4) {
		(this->*f[index])();
		index++;
		std::cout << std::endl;
	}
}

void Harl::debug()
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra onion rings for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra onion rings costs more money. ";
	std::cout << "You didn't put enough onion rings in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra onion rings for free. ";
	std::cout << "I've been coming for years ";
	std::cout << "whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
