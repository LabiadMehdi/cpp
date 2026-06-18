#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &ref) : name(name), weapon(ref)
{
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}