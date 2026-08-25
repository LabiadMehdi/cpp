#pragma once

template<typename T>
void iter(const T* address, size_t length, void (*f)(const T&))
{
	for (size_t i = 0; i < length; i++)
		f(address[i]);
}

template<typename T>
void iter(T* address, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(address[i]);
}