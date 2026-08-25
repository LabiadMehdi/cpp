#include <string>
#include <iostream>
#include <ostream>
#include "iter.hpp"

void    printInt(const int &x)
{
    std::cout << x << std::endl;
}

void    incrementInt(int &x)
{
    x++;
}

void    printString(const std::string &x)
{
    std::cout << x << std::endl;
}

int main( void ) {

    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "before increment" << std::endl;
    ::iter(arr, 5, printInt);
    ::iter(arr, 5, incrementInt);
    std::cout << "after increment" << std::endl;
    ::iter(arr, 5, printInt);

    const int arr2[] = {1, 2, 3, 4, 5};
    std::cout << "const arr" << std::endl;
    ::iter(arr2, 5, printInt);

    std::string strarr[] = {"hello", "bye", "i said bye"};
    std::cout << "string array" << std::endl;
    ::iter(strarr, 3, printString);
    return 0;
}