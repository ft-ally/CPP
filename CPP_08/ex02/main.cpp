
#include <stack>
#include <iostream>

int main()
{
	std::stack<int> test;

	test.push(5);
	std::cout << "Top: " << test.top() << std::endl;
}