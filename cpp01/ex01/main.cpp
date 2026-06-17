#include "Zombie.hpp"

int main(void)
{
	int	numOfZombie = 5;
	Zombie *horde = zombieHorde(numOfZombie, "steve");
	for (int i = 0; i < numOfZombie; i++)
		horde[i].announce();
	delete[] horde;
}