#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat employe1("Elliot", 3);
	std::cout << employe1 << std::endl;

	try
	{
		Bureaucrat employe2("Neo", -2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat employe3("Mr Bean", 234);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat employe4("Boss", 1);
	try
	{
		employe4.increment();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat employe5("Intern", 150);
	try
	{
		employe5.decrement();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}