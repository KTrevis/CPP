#include "Contact.hpp"
#include "colors.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <iostream>
#include <ostream>
#include <string>

class	ContactData {
	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	secret;
		std::string	phoneNumber;
};

static bool	strEmpty(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isspace(str[i]))
			return (false);
	}
	return (true);
}

static bool	isOnlyDigit(std::string str) {
	for(size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			std::cout << RED << "Phone number field should only contain digits!" << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}

static bool	inputValid(std::string str, e_ContactFields field) {
	if (strEmpty(str))
		return (false);
	if (field == PHONENUMBER && !isOnlyDigit(str))
		return (false);
	return (true);
}

void addContact(PhoneBook &book) {
	std::string	str[5];
	
	for (int i = FIRSTNAME; i <= SECRET; i++) {
		while (!inputValid(str[i], (e_ContactFields)i)) {
			std::cout << "Enter contact information: " 
				<< book.getContact(0).enumToStr((e_ContactFields)i) << std::endl << ">> ";
			if (!std::getline(std::cin, str[i]))
				return ;
		}
	}
	book.addContact(str[FIRSTNAME], str[LASTNAME], str[NICKNAME], str[SECRET], str[PHONENUMBER]);
}
