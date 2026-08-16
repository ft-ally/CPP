#include <iostream>
#include <array>
#include <vector>

#include "easyfind.hpp"


template <typename T> void find(T &container, int x)
{
	auto it = easyfind(container, x);
	if (it != container.end())
		std::cout << GREEN << "Found " << x << " in container!" << RESET << std::endl;
	else
		std::cout << x << RED << "not found in container :(" << std::endl;
}

int main()
{
	std::array<int, 6> intArray{4, 8, 15, 16, 23, 42};
	std::vector<int> intVector;
	intVector.insert(intVector.end(), {3, 6, 9});

	std::cout << PINK << "Int Array initialized " << RESET << "{4, 8, 15, 16, 23, 42}" << std::endl;
	std::cout << PINK << "Int Vector initialized " << RESET << "{3, 6, 9}" << std::endl << std::endl;

	try {
		std::cout << CYAN << "===TEST 1: Find 65 in Array====" << RESET << std::endl;
		find(intArray, 65);

	}
	catch (std::exception &e) {
		std::cout << RED << "Exception found: " << RESET << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	try {
		std::cout << CYAN << "===TEST 2: Find 15 in Array====" << RESET << std::endl;
		find(intArray, 15);
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception found: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << CYAN << "===TEST 3: Find 9 in Vector====" << RESET << std::endl;
		find(intVector, 9);

	}
	catch (std::exception &e) {
		std::cout << RED << "Exception found: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << CYAN << "===TEST 4: Find 333 in Vector====" << RESET << std::endl;
		find(intVector, 333);
	}
	catch (std::exception &e) {
		std::cout << RED << "Exception found: " << RESET << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	

}