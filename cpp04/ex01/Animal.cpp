#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor called!" << std::endl; 
}

Animal::~Animal()
{
	std::cout << "Default destructor called!" << std::endl; 
}

void	Animal::makeSound() const
{
	std::cout << "The default animal says:   ...  well he says nothing..." << std::endl; 
}

std::string Animal::getType()
{
	return type;
}