#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact Contacts[8];
		int	tracker;
		int	count;
	public:
		PhoneBook();
		void AddContact(Contact contact);
		int	DisplayContacts();
		int DisplayContact(int index);
		int GetTracker();
		int	GetCount();
};

#endif