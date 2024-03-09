#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string>

enum e_ContactFields {
	FIRSTNAME,
	LASTNAME,
	NICKNAME,
	PHONENUMBER,
	SECRET,
};

class Contact {
	public:
		Contact();
		Contact(std::string firstName, std::string lastName,
			std::string nickname, std::string secret, std::string phoneNumber);
		~Contact();
		std::string getter(e_ContactFields);
		std::string	enumToStr(e_ContactFields);

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_secret;
		std::string	_phoneNumber;
};
#endif
