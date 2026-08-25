#include "ScalarConverter.hpp"
#include <ostream>
#include <iostream>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return 0;
	}
	else
	{
		std::cout << "error" << std::endl;
		return 1;
	}
}