#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	tracker = 0;
	count = 0;
}

void PhoneBook::AddContact(Contact contact)
{
	Contacts[tracker] = contact;
	tracker = (tracker + 1) % 8;
	if (count < 8)
		count++;
	std::cout << "New contact have been sucessfuly added!" << std::endl;
}

int PhoneBook::DisplayContact(int index)
{
	std::cout << "First name: " << Contacts[index - 1].GetFirstName() << std::endl;
	std::cout << "Last name: " << Contacts[index - 1].GetLastName() << std::endl;
	std::cout << "Nick name: " << Contacts[index - 1].GetNickName() << std::endl;
	std::cout << "Phone number: " << Contacts[index - 1].GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << Contacts[index - 1].GetDarkestSecret() << std::endl;
	return (1);
}

std::string truncate(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

int PhoneBook::DisplayContacts()
{
	if (count == 0)
	{
		std::cout << "Your PhoneBook apear to be empty, please try entering ADD and follow";
		std::cout << " the instructions to add a new contact." << std::endl;
		return (0);
	}
	else
		for (int i = 0; i < count; i++)
		{
			std::cout << std::setw(10) << std::right;
			std::cout << i + 1;
			std::cout << "|";
			std::cout << std::setw(10) << std::right;
			std::cout << truncate(Contacts[i].GetFirstName());
			std::cout << "|";
			std::cout << std::setw(10) << std::right;
			std::cout << truncate(Contacts[i].GetLastName());
			std::cout << "|";
			std::cout << std::setw(10) << std::right;
			std::cout << truncate(Contacts[i].GetNickName());
			std::cout << "|";
			std::cout << std::endl;
		}
	return (1);
}

int	PhoneBook::GetTracker()
{
	return tracker;
}

int	PhoneBook::GetCount()
{
	return count;
}