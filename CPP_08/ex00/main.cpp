#include <iostream>
#include <array>
#include "easyfind.hpp"


template <typename T> void printResult(T res)
{
	std::cout << GREEN << "Result: " << RESET << res << std::endl;

}
int main()
{
	std::array<int, 6> intArray{4, 8, 15, 16, 23, 42};
	std::cout << PINK << "INT Array initialized " << RESET << "{4, 8, 15, 16, 23, 42}" << std::endl << std::endl;
	try {
		std::cout << CYAN << "===TEST 1: Find 6====" << RESET << std::endl;
		printResult(easyfind(intArray, 6));
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception found: " << RESET << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	try {
		std::cout << CYAN << "===TEST 2: Find 15====" << RESET << std::endl;
		printResult(easyfind(intArray, 15));
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception found: " << RESET << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	

}