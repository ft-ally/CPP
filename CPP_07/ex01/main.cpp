#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#include "iter.hpp"

template <typename T> static void addFive(T &p)
{
	if constexpr(std::is_same_v<T, std::string>)
		p += "_5";
	else
		p += 5;
}

template <typename T> static void printNonConst(T &p)
{
	std::cout << p << std::endl;
}

template <typename T> static void print(const T &p)
{
	std::cout << p << std::endl;
}



int main()
{
	const size_t size = 5;
	int intArr[size] = {1, 2, 3, 4, 5};
	const int constIntArr[size] = {4, 8, 15, 16, 23};
	char charArr[size] = {'a', 'b', 'c', 'd', 'e'};
	const char constCharArr[size] = {'x', 'd', 'e', 'f', 'g'};


	std::cout << PURPLE << "====TEST 1: Int array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter to print every element" << RESET << std::endl;
	iter(intArr, size, printNonConst);

	std::cout << CYAN << "Test: use iter to add 5 to intArr" << RESET << std::endl;
	iter(intArr, size, addFive);

	std::cout << CYAN << "Test: use iter to print every element" << RESET << std::endl;
	iter(intArr, size, printNonConst);

	std::cout << std::endl << PURPLE << "====TEST 2: Char array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter to print every element" << RESET << std::endl;
	iter(charArr, size, printNonConst);

	std::cout << CYAN << "Test: use iter to add 5 to every element" << RESET << std::endl;
		iter(charArr, size, addFive);

	std::cout << CYAN << "Test: use iter to print every element" << RESET << std::endl;
	iter(charArr, size, printNonConst);
	
	std::cout << std::endl << PURPLE << "====TEST 3: Const int array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter const overload to print every element" << RESET << std::endl;
	iter(constIntArr, size, print);


	std::cout << std::endl << PURPLE << "====TEST 4: Const char array====" << RESET << std::endl;
	std::cout << CYAN << "Test: use iter const overload to print every element" << RESET << std::endl;
	iter(constCharArr, size, print);
}