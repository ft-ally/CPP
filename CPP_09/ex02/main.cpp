#include "PmergeMe.hpp"
#include <sstream>

void validateInput(int argc, char **argv) {
	if (argc < 2)
			throw std::runtime_error("Error, no input");
	for (int i = 1; i < argc; i++) {
		std::string str(argv[i]);
		if (str.find(' ') != std::string::npos)
			throw std::runtime_error("Error, bad input");
		try {
			int num = std::stoi(str);
			if (num <= 0)
				throw std::runtime_error("Error, bad input");
		}
		catch (const std::exception& e) {
			throw std::runtime_error("Error, bad input");
		}
	}
}

void convertInput(int argc, char**argv, std::vector<int> &v, std::deque<int> &d) {
	for (int i = 1; i < argc; i++) {
		int num = std::stoi(argv[i]);
		v.push_back(num);
		d.push_back(num);
	}
}


int main(int argc, char **argv) {
	try {
		validateInput(argc, argv);

		std::vector<int> v;
		std::deque<int> d;
		convertInput(argc, argv, v, d);

		PmergeMe<std::deque<int>> deq(d);
		deq.start();

		PmergeMe<std::vector<int>> vec(v);
		vec.start();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}