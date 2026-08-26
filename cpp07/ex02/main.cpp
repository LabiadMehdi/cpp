#include "Array.hpp"
#include <string>
#include <iostream>
#include <ostream>

int main( void )
{
    Array<int> myIntArray(5);
    Array<int> myOtherIntArray(myIntArray);

    myIntArray[2] = 4;

    std::cout << "myIntArray [2]: " << myIntArray[2] << std::endl;
    std::cout << "myOtherIntArray [2]: " << myOtherIntArray[2] << std::endl;

    try
    {
        myIntArray[99] = 100;
    }
    catch (std::exception & e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    Array<std::string> myStringArray(3);
    Array<std::string> myOtherStringArray(myStringArray);

    myStringArray[2] = "bye";
    myOtherStringArray[2] = "defenetly not bye";

    std::cout << "myStringArray [2]: " << myStringArray[2] << std::endl;
    std::cout << "myStringArray [2]: " << myOtherStringArray[2] << std::endl;

    Array<int> emptyArray;
    std::cout << "emptyArray size: " << emptyArray.size() << std::endl;
}