#include "Fixed.hpp"
#include <iostream>
#define RESET   "\033[0m"
#define MAG "\033[35m"
// int main( void ) 
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );
	
// 	a = Fixed( 1234.4321f );
	
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
	
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	return 0;
// }


int main() 
{
	std::cout << MAG << "=== TEST 1: DEFAULT CONSTRUCTOR ===" << RESET << std::endl;
	Fixed a;
	std::cout << std::endl;

	std::cout << MAG << "=== TEST 2: INT CONSTRUCTOR ===" << RESET << std::endl;
	std::cout << "B is set to 10" << std::endl;
	Fixed const b(10);
	std::cout << std::endl;

	std::cout << MAG << "=== TEST 3: FLOAT CONSTRUCTOR ===" << RESET << std::endl;
	std::cout << "C is set to 42.42f" << std::endl;
	Fixed const c(42.42f);
	std::cout << std::endl;

	std::cout << MAG << "=== TEST 4: COPY CONSTRUCTOR ===" << RESET << std::endl;
	std::cout << "B copied to D" << std::endl;
	Fixed const d( b );
	std::cout << std::endl;

	std::cout << MAG << "=== TEST 5: COPY ASSIGNMENT OPERATOR ===" << RESET << std::endl;
	std::cout << "A assigned 1234.4321f" << std::endl;
	a = Fixed( 1234.4321f );
	std::cout << std::endl;

	std::cout << MAG << "=== TEST 6: OUTPUT OPERATOR ===" << RESET << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << std::endl;

	std::cout << MAG << "=== TEST 7: TOINT MEMBER FUNCTION ===" << RESET << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << MAG << "=== TEST 8: TOFLOAT MEMBER FUNCTION ===" << RESET << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << std::endl;
	
	std::cout << MAG << "=== DESTRUCTORS ===" << RESET << std::endl;

	return 0;
}

