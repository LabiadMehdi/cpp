#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact Contacts[8];
		int	tracker;
	public:
		PhoneBook();
		void AddContact(Contact contact);
		int DisplayContacts();
		void DisplayContact(int index);
};

#endif