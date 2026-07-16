#include "Colors.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.cpp"

#include <exception>

int main()
{
	try
	{
		std::cout << "======TEST 1: Serialize========" << std::endl;

		std::cout << "======TEST 2: Deserialize========" << std::endl;
	
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}