
#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define CYAN    "\033[36m"

// int main( void ) 
// {
// 	Fixed a;
// 	Fixed b( a );
// 	Fixed c;
	
// 	c = b;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
// 	return 0;
// }

int main( void ) 
{
	std::cout << CYAN << "=== TEST 1: DEFAULT CONSTRUCTOR ===" << RESET << std::endl;
	Fixed a;
	Fixed c;
	std::cout << std::endl;

	std::cout <<CYAN << "=== TEST 2: COPY CONSTRUCTOR ===" << RESET << std::endl;
	std::cout << "Fixed b(a):" << std::endl;
	Fixed b(a);
	std::cout << std::endl;

	std::cout << CYAN << "==TEST 3: GETRAWBITS ===" << RESET << std::endl;
	std::cout << "A: " << a.getRawBits() << std::endl;
	std::cout << "B: " << b.getRawBits() << std::endl;
	std::cout << "C: " << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "==TEST 4: SETRAWBITS ===" << RESET << std::endl;
	std::cout << "A: set to 5" << std::endl;
	a.setRawBits(5);
	std::cout << std::endl;
	std::cout << "B: set to 10" << std::endl;
	b.setRawBits(10);
	std::cout << std::endl;
	std::cout << "C: set to 8" << std::endl;
	c.setRawBits(8);
	std::cout << std::endl;

	std::cout << CYAN << "==TEST 5: GETRAWBITS AFTER SET===" << RESET << std::endl;
	std::cout << "A: " << a.getRawBits() << std::endl;
	std::cout << "B: " << b.getRawBits() << std::endl;
	std::cout << "C: " << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "==TEST 6: COPY ASSIGNMENT OPERATOR ===" << RESET << std::endl;
	std::cout << "B copied to C" << std::endl;
	c = b;
	std::cout << std::endl;

	std::cout << CYAN << "==TEST 7: GETRAWBITS AFTER COPY ===" << RESET << std::endl;
	std::cout << "B: " << b.getRawBits() << std::endl;
	std::cout << "C: " << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN << "==TEST 8: DESTRUCTORS ===" << RESET << std::endl;
	return 0;
}