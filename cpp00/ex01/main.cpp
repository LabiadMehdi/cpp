#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "ErrIns.hpp"
#include <iostream>

int main()
{
	PhoneBook	pb;
	std::string	command;
	std::string	info;
	std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
	while (1)
	{
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			Contact contact = fill_contact();
			pb.AddContact(contact);
		}
		else if (command == "SEARCH")
		{
			if (pb.DisplayContacts())
			{
				int index = check_for_index(pb.GetCount());
				if (index == -1)
					break ;
				else if (index)
				{
					if (!(pb.DisplayContact(index)))
					{
						std::cout << "The contact you are trying to reach do not exist!";
						std::cout<< std::endl;
					}
				}

			}
		}
		else
		{
			std::cout << "Command: \"" + command + "\" is unknown." << std::endl;
			std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
		}
	}
	return (0);
}