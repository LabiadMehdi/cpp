#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook	pb;
	std::string	command;
	std::string	info;
	std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl
	while (1)
	{
		std::cin >> command;
		std::cin.ignore();
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			Contact contact;
			std::getline(std::cin, info);
			contact.SetFirstName(info);
			std::getline(std::cin, info);
			contact.SetLastName(info);
			std::getline(std::cin, info);
			contact.SetNickName(info);
			std::getline(std::cin, info);
			contact.SetPhoneNumber(info);
			std::getline(std::cin, info);
			contact.SetDarkestSecret(info);
			pb.AddContact(contact);
		}
		else if (command == "SEARCH")
		{
			if (pb.DisplayContacts())
			{
				int index;
				if ((index = check_for_index()))
				{
					std::cin.ignore();
					pb.DisplayContact(index);
				}
			}
		}
		else
		{
			std::cout << "Command: \"" + command + "\" is unknown." << std::endl;
			std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl
		}
	}
	return (0);
}