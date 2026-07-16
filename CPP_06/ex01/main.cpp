#include "Data.hpp"
#include "Serializer.hpp"
#include "Colors.hpp"
#include <exception>

int main()
{
	try
	{
		std::cout << "======TEST 1: Serialize========" << std::endl;
		Data *data1 = new Data("hello world");
		std::cout << BLUE << "Data address before serialization: " << RESET << data1 << std::endl;
		std::cout << PINK << "Data string: " << RESET << data1->getString() << std::endl << std::endl;
		std::cout << GREEN << "Calling Serializer..." <<std::endl;
		uintptr_t addr = Serializer::serialize(data1);
		std::cout << BLUE << "Data address after serialization: " << RESET << addr << std::endl << std::endl;
		std::cout << "======TEST 2: Deserialize========" << std::endl;
		Data *data2 = Serializer::deserialize(addr);
		std::cout << PINK << "Data address after deserialization: " << RESET << data2 << std::endl;
		std::cout << BLUE << "Data string: " << RESET << data2->getString() << std::endl;
		
		delete data1;
		
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}