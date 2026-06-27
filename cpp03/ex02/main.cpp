#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap barry = ClapTrap("barry");
	std::cout << barry.getName() << " " << barry.getEnergyPoints() << " " << barry.getHitPoints() << " " << barry.getAttackDmg() << std::endl;
	barry.attack("jhon");
	barry.takeDamage(3);
	barry.beRepaired(1);
	std::cout << barry.getName() << " " << barry.getEnergyPoints() << " " << barry.getHitPoints() << " " << barry.getAttackDmg() << std::endl;
	
	std::cout << std::endl << std::endl;

	ScavTrap steve = ScavTrap("steve");
	std::cout << steve.getName() << " " << steve.getEnergyPoints() << " " << steve.getHitPoints() << " " << steve.getAttackDmg() << std::endl;
	steve.attack("jhon");
	steve.takeDamage(3);
	steve.beRepaired(1);
	std::cout << steve.getName() << " " << steve.getEnergyPoints() << " " << steve.getHitPoints() << " " << steve.getAttackDmg() << std::endl;
	steve.guardGate();

	std::cout << std::endl << std::endl;

	FragTrap rose = FragTrap("rose");
	std::cout << rose.getName() << " " << rose.getEnergyPoints() << " " << rose.getHitPoints() << " " << rose.getAttackDmg() << std::endl;
	rose.attack("jhon");
	rose.takeDamage(3);
	rose.beRepaired(1);
	std::cout << rose.getName() << " " << rose.getEnergyPoints() << " " << rose.getHitPoints() << " " << rose.getAttackDmg() << std::endl;
	rose.highFivesGuys();
}