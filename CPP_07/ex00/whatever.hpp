#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> 

void swap(T& i, T& j)
{
	T tmp;
	tmp = i;
	i = j;
	j = tmp;
}

template <typename T>

T min(T i, T j)
{
	return (i < j ? i : j);
}

template <typename T>

T max(T i, T j)
{
	return (i > j ? i : j);
}
#endif