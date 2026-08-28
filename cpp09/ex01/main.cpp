#include <iostream>
#include <ostream>
#include <exception>
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try
	{
		int result = RPN::evaluate(av[1]);
		std::cout << result << std::endl;
		return 0;
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
}