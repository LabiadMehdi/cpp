#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << "I love having extra [...] burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding [...] I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have [...] here just last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	int	levelLength = sizeof(levels) / sizeof(levels[0]);
	for (int i = 0; i < levelLength; i++)
	{
		if (levels[i] == level)
			(this->*functions[i])();
	}
}