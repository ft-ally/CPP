#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

struct pair {
	int a; //bigger number
	int b; //smaller number
};

template <typename Container> 
class PmergeMe {
	private:
		Container _c;
		int _comparisons;
	public:
	PmergeMe();
	PmergeMe(const Container& input);
	PmergeMe(const PmergeMe &src);
	PmergeMe& operator=(const PmergeMe &src);
	~PmergeMe();

	void pairElements();
	void start();
	
	static_assert(
		(std::is_same_v<std::vector<int>, T> 
		|| std::is_same_v<std::deque<int>, T>),
		"Error, unsupported container type. Use vector or deque"
	);
};

template <typename Container>
PmergeMe<Container>::PmergeMe(const Container& input)
	: _c(input) {}
	
	
template <typename Container> PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
void pairElements(Container &c) {
	Container newContainer;
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		int prevNum = *it;
		int curNum = ++it;

		pair currentPair;
		if (prevNum < curNum) {
			currentPair.a = curNum;
			currentPair.b = prevNum;
		}
		else {
			currentPair.a = prevNum;
			currentPair.b = curNum;
		}
		newContainer.push_back(currentPair);
	}
}

template <typename Container>
Container sortLevel(Container c) {
	if (c.size() <= 2) {
		if (c.begin()->val > c.end()->val) {
			std::swap(*c.begin(), *c.end());
		}
		return c;
	}
	int straggler;
	straggler = 0;
	if (c.size() % 2 == 1) {
		straggler = c.back();
		c.pop_back();
	}
	std::vector<pair> pairs;
	pairElements(c);
	c = sortLevel(c);
	//insert b numbers to main chain
	return c;
}

template <typename Container>
void PmergeMe<Container>::start() {
	_container = sortLevel(_container);
	//add
	//recursion base case
	//check if even, if not even, put the last element inside a variable and pop back
}

/* 
phase 1: pair and sort recursively 
split into pairs
sort inside pairs, put the lower number first
take the larger number (winners), and sort them but keeping their old pair


*/
#endif

