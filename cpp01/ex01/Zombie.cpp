#include "Zombie.hpp"

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << name << ": has joined the hord!" << std::endl;
}