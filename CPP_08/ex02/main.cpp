
#include <list>

#include <iostream>
#include "MutantStack.hpp"
#include "Colors.hpp"


void testExample()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << "Elements: " << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "S size: " << s.size() << std::endl;

}

void replaceList()
{
	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << "Top: " << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << "Size: " << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);
	std::list<int>::iterator it = lstack.begin();
	std::list<int>::iterator ite = lstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Elements: " << *it << std::endl;
		++it;
	}
	std::stack<int, std::list<int>> s(lstack);
	std::cout << "S size: " << s.size() << std::endl;


}

int main()
{
	std::cout << GREEN << "=======Test: Intra Test======" << RESET << std::endl;

	testExample();
	std::cout << GREEN << "=======Test: Replace Mutant Stack with List======" << RESET << std::endl;
	replaceList();
	std::cout << GREEN << "=======OTHER TESTS======" << RESET << std::endl;
	std::cout << CYAN << "//string MStack Initialized {first, second, third, fourth}" << RESET << std::endl;

	MutantStack<std::string> mstack;
	mstack.push("first");
	mstack.push("second");
	mstack.push("third");
	mstack.push("fourth");

	std::cout << CYAN << "//copied MStack to copyStack" << RESET << std::endl << std::endl;
	MutantStack<std::string> copyStack(mstack);

	std::cout << PURPLE << "======= TEST: Print MStack content using iterators ======" << RESET << std::endl;
	for (auto it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << GREEN << "Top: " << RESET << mstack.top() << std::endl;
	

	std::cout << PURPLE << "======= TEST: Print copyStack content using iterators ======" << RESET << std::endl;
	for (auto it = copyStack.begin(); it != copyStack.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << GREEN << "Top: " << RESET << copyStack.top() << std::endl;

	std::cout << std::endl;

	std::cout << CYAN << "//int stack initialized {4, 8, 15, 16, 23}" << RESET << std::endl;
	MutantStack<int> intStack;
	intStack.push(4);
	intStack.push(8);
	intStack.push(15);
	intStack.push(16);
	intStack.push(23);

	std::cout << PURPLE << "======= TEST: Print intStack content using iterators ======" << RESET << std::endl;
	for (auto it = intStack.begin(); it != intStack.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << GREEN << "Top: " << RESET << intStack.top() << std::endl;
	std::cout << PURPLE << "======= TEST: Get size of intStack ======" << RESET << std::endl;
	std::cout << GREEN << "Size: " << intStack.size() << std::endl;
	std::cout << PURPLE << "======= TEST: Use pop to remove last 2 added elements ======" << RESET << std::endl;
	intStack.pop();
	intStack.pop();
	for (auto it = intStack.begin(); it != intStack.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << GREEN << "Top: " << RESET << intStack.top() << std::endl;
	std::cout << PURPLE << "======= TEST: Get new size of intStack ======" << RESET << std::endl;
	std::cout << GREEN << "Size: " << intStack.size() <<std::endl;

}