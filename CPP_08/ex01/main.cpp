#include "Span.hpp"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define BLUE "\033[34m"
#define PINK "\033[95m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"


#include <iostream>

void printIntraTest()
{
	std::cout << GREEN << "=======INTRA TEST======" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << PURPLE << "EXPECTED: " << RESET << std::endl;
	std::cout << "2" << std::endl << "14" << std::endl << std::endl;
	
	std::cout << PURPLE << "ACTUAL: " << RESET << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;
	
}

int main()
{
	printIntraTest();
	std::cout << GREEN << "=======OTHER TESTS======" << RESET << std::endl;
	Span testSpan(5);
	try {
		std::cout << PURPLE << "======= TEST 1: Initialize span with 5 elements and add more than 5 elements ======" << RESET << std::endl;

		for (int i = 0; i < 6; i++)
		{
			testSpan.addNumber(20);
		}
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << PURPLE << "======= TEST 2: Longest and shortest span======" << RESET << std::endl;
	std::cout << PURPLE << "Elements: {4, 8, 15, 16, 23, 42}" << RESET << std::endl;
	Span testSpan2(6);
	testSpan2.addNumber(4);
	testSpan2.addNumber(8);
	testSpan2.addNumber(15);
	testSpan2.addNumber(16);
	testSpan2.addNumber(23);
	testSpan2.addNumber(42);
	
	std::cout << "Shortest span is: " << testSpan2.shortestSpan() << std::endl;
	std::cout << "Longest span is: " << testSpan2.longestSpan() << std::endl;

		std::cout << PURPLE << "======= TEST 3: Longest and shortest span======" << RESET << std::endl;
	std::cout << PURPLE << "Elements: {}" << RESET << std::endl;
	Span testSpan3(0);
	try {
		std::cout << "Shortest span is: " << testSpan3.shortestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try {
		std::cout << "Longest span is: " << testSpan3.longestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}