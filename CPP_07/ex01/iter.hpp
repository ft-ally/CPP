#ifndef ITER_TPP
#define ITER_TPP

#include <iostream>

template <typename T>
void iter(T *addr, const size_t arrLen, void(*func)(T&))
{
	std::cout << "Using the non-const overload" << std::endl;
	for (size_t i = 0; i < arrLen; i++)
	{
		func(addr[i]);
	}
}

template <typename T>
void iter(const T *addr, const size_t arrLen, void(*func)(const T&))
{
	std::cout << "Using the const overload" << std::endl;
	for (size_t i = 0; i < arrLen; i++)
	{
		func(addr[i]);
	}
}

#endif