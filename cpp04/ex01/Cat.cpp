#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called!" << std::endl; 
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called!" << std::endl; 
}

void	Cat::makeSound() const
{
	std::cout << "The cat says: miaaaouuu.. Hhhhiiiiisss" << std::endl; 
}

Cat::Cat(const Cat &other)
{
	type = other.type;
    brain = new Brain();
	*brain = *other.brain;
}

Cat&	Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	type = other.type;
	delete brain;
    brain = new Brain();
	*brain = *other.brain;
	return *this;
}

Brain* Cat::getBrain()
{
	return brain;
}