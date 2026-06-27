#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap barry = ClapTrap("barry");
	std::cout << barry.getName() << " " << barry.getEnergyPoints() << " " << barry.getHitPoints() << " " << barry.getAttackDmg() << std::endl;
	barry.attack("jhon");
	barry.takeDamage(3);
	barry.beRepaired(1);
	std::cout << barry.getName() << " " << barry.getEnergyPoints() << " " << barry.getHitPoints() << " " << barry.getAttackDmg() << std::endl;
}