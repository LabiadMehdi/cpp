#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

std::string Brain::getIdeas(int n)
{
	return ideas[n];
}

void	Brain::setIdeas(int n, std::string s)
{
	ideas[n] = s;
}