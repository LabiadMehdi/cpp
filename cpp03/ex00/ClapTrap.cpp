#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << name << " has no more energy and/or hitPoints to attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints = hitPoints - amount;
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		energyPoints--;
		hitPoints = hitPoints + amount;
		std::cout << "ClapTrap healed " << amount << "!" << std::endl;
	}
	else
		std::cout << name << " has no more energy!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDmg(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

std::string ClapTrap::getName()
{
	return name;
}

int ClapTrap::getHitPoints()
{
	return hitPoints;
}

int ClapTrap::getEnergyPoints()
{
	return energyPoints;
}

int ClapTrap::getAttackDmg()
{
	return attackDmg;
}