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

};

//get the string
//check how many elements, divide by 2, upper bound. that's how many times for the loop
//do it recursively on each pair?
#endif

