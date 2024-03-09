#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "colors.hpp"

static std::string	missingSpaces(std::string &str) {
	std::string	new_str;
	const int	size = 10 - str.length();
	if (size > 0)
		new_str.resize(size, ' ');
	return new_str;
}

static std::string	formattedDisplay(Contact contact, e_ContactFields contactData) {
	std::string	str = contact.getter(contactData);

	if (str.length() > 10) {
		str.erase(10);
		str[9] = '.';
	}
	std::cout << str << missingSpaces(str) << "|";
	return str;
}

static void	findContactWithId(PhoneBook &book) {
	std::string		str;

	std::cout << std::endl << "Enter the ID of a user to display its informations." << std::endl;
	std::cout << ">> ";
	if (!std::getline(std::cin, str))
		return ;

	int n = std::atoi(str.c_str());
	if (n < 0 || n > book.getContactCount() - 1) {
		std::cout << RED << "No user with this ID exists." << RESET << std::endl;
		return ;
	}

	Contact contact = book.getContact(n);
	for (int i = FIRSTNAME; i <= SECRET; i++) {
		std::cout << contact.enumToStr((e_ContactFields)i) << ":\t"
			<< contact.getter((e_ContactFields)i) << std::endl;
	}
}

void	searchContact(PhoneBook &book) {
	if (book.getContactCount() == 0) {
		std::cout << RED << "The phonebook is empty." << RESET << std::endl;
		return ;
	}
	std::cout << CYAN << "|    ID    |First Name|Last  Name| Nickname |Phone num.|" << std::endl;
	std::cout << "|          |          |          |          |          |" << std::endl;

	for (int i = 0; i < book.getContactCount(); i++) {
		Contact curr = book.getContact(i);
		std::cout << "|    " << i << "     |";
		for (int j = FIRSTNAME; j <= PHONENUMBER; j++)
			formattedDisplay(curr, (e_ContactFields)j);
		std::cout << RESET << std::endl;
	}
	findContactWithId(book);
}
