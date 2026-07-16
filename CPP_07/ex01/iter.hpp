#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void iter(T *addr, T arrLen, void(*func)(T&))
{
	for (size_t i = 0; i < arrLen; i++)
	{
		func(address[i]);
	}
}

template <typename T>

void iter(const T *addr, T arrLen, void(*func)(const T&))
{
	for (size_t i = 0; i < arrLen; i++)
	{
		func(address[i]);
	}
}

#endif