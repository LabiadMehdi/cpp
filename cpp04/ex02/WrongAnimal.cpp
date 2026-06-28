#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor called!" << std::endl; 
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default destructor called!" << std::endl; 
}

void	WrongAnimal::makeSound() const
{
	std::cout << "The default wrong animal says:   ...  well he says nothing..." << std::endl; 
}

std::string WrongAnimal::getType()
{
	return type;
}