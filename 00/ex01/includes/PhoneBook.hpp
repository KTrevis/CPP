#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		Contact	getContact(int index);
		int		getContactCount();
		void	addContact(std::string firstName, std::string lastName,
		std::string nickname, std::string secret, std::string phoneNumber);

	private:
		Contact	_contacts[8];
		int		_contactCount;
		int		_oldestContact;
};
#endif
