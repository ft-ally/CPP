#ifndef ITER_TPP
#define ITER_TPP

#include <iostream>

template <typename T>

void iter(T *addr, size_t arrLen, void(*func)(T&))
{
	for (size_t i = 0; i < arrLen; i++)
	{
		func(addr[i]);
	}
}

template <typename T>

void iter(const T *addr, size_t arrLen, void(*func)(const T&))
{
	for (size_t i = 0; i < arrLen; i++)
	{
		func(addr[i]);
	}
}

#endif