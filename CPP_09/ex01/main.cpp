#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc < 2)
		std::cout << "Error, bad input\n";
	try {
		RPN rpn(argv[1]);
	} 
	catch (std::exception &e) {
		std::cerr << e.what();
	}
}