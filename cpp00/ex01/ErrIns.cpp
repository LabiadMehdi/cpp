#include <iostream>
#include "ErrIns.hpp"
#include <stdlib.h>

int	check_for_index(int tracker)
{
	std::string	indexStr;
	std::getline(std::cin, indexStr);
	int index = atoi(indexStr.c_str());
	if (index >= 1 && index <= tracker)
		return (index);
	std::cout << "Cannot display \"" << indexStr << "\"." << std::endl;
	std::cout << "You have " << tracker;
	std::cout << " contact(s), use SEARCH again and please try a number between 1 and ";
	std::cout << tracker << std::endl;
	return (0);
}