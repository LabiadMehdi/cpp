#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDmg = 20;
	std::cout << "Constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << name << " has no more energy and/or hitPoints to attack" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << name << " is now in gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called on " << name << "." << std::endl;
}