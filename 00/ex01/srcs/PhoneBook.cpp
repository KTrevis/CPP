#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
	this->_contactCount = 0;
	this->_oldestContact = 0;
}

PhoneBook::~PhoneBook() {}

int		PhoneBook::getContactCount() {
	return this->_contactCount;
}

void	PhoneBook::addContact(std::string firstName, std::string lastName,
	std::string nickname, std::string secret, std::string phoneNumber) {
	int	index;

	if (this->_contactCount < 8)
		index = this->_contactCount++;
	else
		index = this->_oldestContact++;
	this->_oldestContact %= 8; // goes back to 0 if equal to 8, because index 7 is the max
	this->_contacts[index] = Contact(firstName, lastName, nickname, secret, phoneNumber);
	std::cout << "Successfully created new contact !" << std::endl;
}

Contact	PhoneBook::getContact(int index) {
	return this->_contacts[index];
}
