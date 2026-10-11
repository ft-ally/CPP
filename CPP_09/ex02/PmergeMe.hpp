#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

template <typename T> 
class PmergeMe {
	private:
		T container;
	public:
	PmergeMe();
	PmergeMe(const T& input);
	PmergeMe(const PmergeMe &src);
	PmergeMe& operator=(const PmergeMe &src);
	~PmergeMe();

	void start();
	
	static_assert(
		(std::is_same_v<std::vector<int>, T> 
		|| std::is_same_v<std::deque<int>, T>),
		"Error, unsupported container type. Use vector or deque"
	);
};

template <typename T>
PmergeMe<T>::PmergeMe(const T& input)
	: container(input) {}
	
	
template <typename T> PmergeMe<T>::~PmergeMe() {}

template <typename T>
void PmergeMe<T>::start() {}

/* 
phase 1: pair and sort recursively 
split into pairs
sort inside pairs, put the lower number first
take the larger number (winners), and sort them but keeping their old pair


*/
#endif

