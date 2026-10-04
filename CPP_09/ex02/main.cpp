#include "PmergeMe.hpp"
#include "utils.cpp"
#include <sstream>


int main(int argc, char **argv) {
	try {
		validateInput(argc, argv);

		std::vector<int> v;
		std::deque<int> d;
		convertInput(argc, argv, v, d);

		PmergeMe<std::deque<int>> deq(d);
		deq.sort();

		PmergeMe<std::vector<int>> vec(v);
		vec.sort();
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}