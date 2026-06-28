#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor called!" << std::endl; 
}

Animal::~Animal()
{
	std::cout << "Default destructor called!" << std::endl; 
}

std::string Animal::getType()
{
	return type;
}