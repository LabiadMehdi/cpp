#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data myData;
	myData.age = 25;
	myData.name = "Néo";
	myData.dateOfBirth = "01/01/2001";
	myData.sex = "male";
	myData.country = "U.S.A";

	Data *originalPtr = &myData;

	uintptr_t raw = Serializer::serialize(originalPtr);
	Data *newPtr = Serializer::deserialize(raw);

	if (newPtr == originalPtr)
		std::cout << "SUCCESS: pointers match" << std::endl;
	else
		std::cout << "FAILURE: pointers do not match" << std::endl;
	std::cout << "raw: " << std::hex << raw << std::endl;
	std::cout << "Name via new pointer: " << newPtr->name << std::endl;
	return 0;
} 