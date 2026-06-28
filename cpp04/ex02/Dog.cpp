#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called!" << std::endl; 
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called!" << std::endl; 
}

void	Dog::makeSound() const
{
	std::cout << "The dog says: bark.. bark.." << std::endl;
}

Dog::Dog(const Dog &other)
{
	type = other.type;
    brain = new Brain();
	*brain = *other.brain;
}

Dog&	Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	type = other.type;
	delete brain;
    brain = new Brain();
	*brain = *other.brain;
	return *this;
}

Brain* Dog::getBrain()
{
	return brain;
}