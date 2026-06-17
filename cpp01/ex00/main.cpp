#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie *z = newZombie("Foo");
	z->announce();
	delete z;
	randomChump("Bar");
	return (0);
}