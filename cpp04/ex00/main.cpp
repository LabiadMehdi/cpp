#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal* animal = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();

	std::cout << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();

	delete animal;
	delete cat;
	delete dog;
	delete wrongAnimal;
	delete wrongCat;
}