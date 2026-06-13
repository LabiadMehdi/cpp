#include <iostream>
#include "ErrIns.hpp"
#include <stdlib.h>
#include <string>

int	check_for_index(int count)
{
	std::string	indexStr;
	int index;
	while (1)
	{
		std::getline(std::cin, indexStr);
		if (std::cin.eof())
			return (-1);
		index = atoi(indexStr.c_str());
		if (!(index >= 1 && index <= count))
		{
			std::cout << "Cannot display \"" << indexStr << "\"." << std::endl;
			std::cout << "You have " << count;
			std::cout << " contact(s), please try a number between 1 and ";
			std::cout << count << std::endl;
		}
		else
			break ;
	}
	return (index);
}

int	empty(std::string info)
{
	if (info.compare("") == 0)
	{
		std::cout << "Empty fields are not possible. Please enter a valid info." << std::endl;
		return (1);
	}
	else return (0);
}

Contact	fill_contact()
{
	Contact contact;
	std::string info;
	
	do
	{
		std::cout << "First name: ";
		std::getline(std::cin, info);
		if (std::cin.eof())
			exit(0);
	} while (empty(info));
	contact.SetFirstName(info);

	do
	{
		std::cout << "Last name: ";
		std::getline(std::cin, info);
		if (std::cin.eof())
			exit(0);
	} while (empty(info));
	contact.SetLastName(info);
	
	do
	{
		std::cout << "Nick name: ";
		std::getline(std::cin, info);
		if (std::cin.eof())
			exit(0);
	} while (empty(info));
	contact.SetNickName(info);
	
	do
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, info);
		if (std::cin.eof())
			exit(0);
	} while (empty(info));
	contact.SetPhoneNumber(info);
	
	do
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, info);
		if (std::cin.eof())
			exit(0);
	} while (empty(info));
	contact.SetDarkestSecret(info);

	return (contact);
}