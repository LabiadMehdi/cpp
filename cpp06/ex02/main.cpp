#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <iostream>


Base	*generate(void)
{
	int r = std::rand() % 3;
	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return ;
	}
	else
	{
		std::cout << "unknown" << std::endl;
		return ;
	}
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch(...)
	{
	}
	try
	{
		B &a = dynamic_cast<B&>(p);
		(void)a;
		std::cout << "B" << std::endl;
		return;
	}
	catch(...)
	{
	}
	try
	{
		C &a = dynamic_cast<C&>(p);
		(void)a;
		std::cout << "C" << std::endl;
		return;
	}
	catch(...)
	{
	}
	std::cout << "unknown" << std::endl;
}

int main(void)
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Base *rand = generate();
		identify(rand);
		identify(*rand);
		delete rand;
	}
	return 0;
}