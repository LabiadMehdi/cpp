#include "Span.hpp"
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>


int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: Span is full" << std::endl;
	}
	
	Span emptySpan = Span(3);
	try
	{
		std::cout << emptySpan.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: Span is empty" << std::endl;
	}


	std::srand(std::time(NULL));

	std::vector<int> bigData;
	for (int i = 0; i < 10000; i++)
		bigData.push_back(std::rand());
	Span bigSpan = Span(10000);
	bigSpan.addRange(bigData.begin(), bigData.end());
	std::cout << bigSpan.shortestSpan() << std::endl;
	std::cout << bigSpan.longestSpan() << std::endl;
	
	return 0;
}