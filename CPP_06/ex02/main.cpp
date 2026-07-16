#include "Colors.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"

#include <exception>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(NULL));
	try
	{
		std::cout << "======TEST 1: Generate========" << std::endl;
		Base *classes[5];
		for (int i = 0; i < 5; i++)
		{
			classes[i] = generate();
			std::cout << GREEN << "Random class generated at index " << i << std::endl << RESET;
		}
		
		std::cout << std::endl << "======TEST 2: Identify Pointer ========" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << PURPLE << "Class pointer at index " << i << " identified as " << RESET;
			identify(classes[i]);
		}
		std::cout << std::endl << "======TEST 3: Identify Reference ========" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << PURPLE << "Class reference at index " << i << " identified as " << RESET;
			identify(*classes[i]);
		}
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}