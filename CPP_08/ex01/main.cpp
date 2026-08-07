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

}