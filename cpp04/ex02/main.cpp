#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	// Animal* a = new Animal();
	Dog dog1;
	Dog dog2 = dog1;

	dog1.getBrain()->setIdeas(2, "dog1");
	dog2.getBrain()->setIdeas(2, "dog2");

	std::cout << dog1.getBrain()->getIdeas(2) << std::endl;
	std::cout << dog2.getBrain()->getIdeas(2) << std::endl;
}