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

	sort();
	
	static_assert(
		(std::is_same_v<std::vector<int>, T> 
		|| std::is_same_v<std::deque<int>, T>),
		"Error, unsupported container type. Use vector or deque"
	)
};
//should i put back the static assert??

//get the string
//check how many elements, divide by 2, upper bound. that's how many times for the loop
//do it recursively on each pair?
#endif

