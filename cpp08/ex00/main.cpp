#include "easyfind.hpp"
#include <list>


int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> values(arr, arr + 5);

	std::vector<int>::iterator it = easyfind(values, 2);
	std::cout << *it << std::endl;
	it = easyfind(values, 42);
	if (it != values.end())
		std::cout << *it << std::endl;
	else
		std::cout << "not found" << std::endl;


	std::list<int> listValues(arr, arr + 5);

	std::list<int>::iterator nit = easyfind(listValues, 2);
	std::cout << *nit << std::endl;
	nit = easyfind(listValues, 42);
	if (nit != listValues.end())
		std::cout << *nit << std::endl;
	else
		std::cout << "not found" << std::endl;

	return 0;
}