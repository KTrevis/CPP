#include "PhoneBook.hpp"
#include "add.hpp"
#include "search.hpp"
#include "colors.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

void parseCommand(PhoneBook &book, std::string str) {
	if (str == "ADD")
		return addContact(book);
	if (str == "SEARCH")
		return searchContact(book);
	std::cout << RED << str << ": command not found" << RESET << std::endl;
}

int main() {
	PhoneBook book;
	std::string	str;
	
	std::cout << "Commands available: ADD, SEARCH, EXIT" << std::endl;
	while (true) {
		std::cout << "> ";
		if (!std::getline(std::cin, str) || str == "EXIT")
			break ;
		parseCommand(book, str);
	}
}
