#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDmg = 30;
	std::cout << "Constructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << name << " has no more energy and/or hitPoints to attack" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << name << " calling for a high five!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called on " << name << "." << std::endl;
}