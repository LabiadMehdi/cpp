#include <iostream>

int	check_for_index()
{
	std::string	indexStr;
	std::getline(std::cin >> indexStr);
	int index = std::stoi(indexStr);
	if (index >= 0 && index <= 8)
		return (1);
	std::cout << "Invalid input \"" << indexStr << "\""
}