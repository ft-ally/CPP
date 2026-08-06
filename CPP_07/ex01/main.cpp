#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#include "iter.hpp"

template <typename T> static void print(const T &p)
{
	std::cout << p << std::endl;
}

template <typename T> static void printNonConst(T &p)
{
	std::cout << p << std::endl;
}


int main()
{
	const size_t size = 5;
	int intArr[size] = {1, 2, 3, 4, 5};
	const int constIntArr[size] = {4, 8, 15, 16, 23};
	char charArr[size] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << PURPLE << "====TEST 1: Int array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter to print every element" << RESET << std::endl;
	iter(intArr, size, printNonConst);

	std::cout << std::endl << PURPLE << "====TEST 2: Char array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter to print every element" << RESET << std::endl;
	iter(charArr, size, printNonConst);
	
	
	std::cout << std::endl << PURPLE << "====TEST 3: Const int array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter const overload to print every element" << RESET << std::endl;
	iter(constIntArr, size, print);
}