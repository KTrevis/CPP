#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickname, std::string secret, std::string phoneNumber):
	_firstName(firstName), _lastName(lastName), _nickname(nickname), _secret(secret), _phoneNumber(phoneNumber) {}

Contact::~Contact() {}

std::string Contact::getter(e_ContactFields data) {
	switch (data) {
		case FIRSTNAME:
			return this->_firstName;
		case LASTNAME:
			return this->_lastName;
		case NICKNAME:
			return this->_nickname;
		case SECRET:
			return this->_secret;
		case PHONENUMBER:
			return this->_phoneNumber;
	}
	return "";
}

std::string	Contact::enumToStr(e_ContactFields data) {
	std::string	str[SECRET + 1] = {
		"First name",
		"Last name",
		"Nick name",
		"Phone number",
		"Darkest secret"
	};
	return str[data];
}
