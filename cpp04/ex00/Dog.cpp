#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called!" << std::endl; 
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl; 
}

void	Dog::makeSound() const
{
	std::cout << "The dog says: bark.. bark.." << std::endl; 
}