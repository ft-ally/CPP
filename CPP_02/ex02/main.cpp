#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define OR  "\033[38;5;208m"

// int main( void ) 
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int main (void)
{
	std::cout << OR << "=== TEST 1: CONSTRUCTORS ===" << RESET << std::endl;
	std::cout << "A is set to 5.5f" << std::endl;
	std::cout << "B is set to 10" << std::endl;
	std::cout << "C is set to 1" << std::endl;
	Fixed a(5.50f);
	Fixed b(10);
	Fixed c(1);
	std::cout << std::endl;

	std::cout << OR << "=== TEST 2 and 3: >  and >= overload ===" << RESET << std::endl;
	std::cout << OR << "A > B?" << RESET << std::endl;
	if (a > b)
	 	std::cout << "Yes\n";
	else
	 	std::cout << "No\n";
	std::cout << OR << "B >= C?" RESET << std::endl;
	if (b >= c)
	 	std::cout << "Yes\n";
	else
	 	std::cout << "NO\n";
	std::cout << std::endl;

	std::cout << OR << "=== TEST 4 and 5: != and == overload ===" << RESET << std::endl;
	std::cout << OR << "A != B?" << RESET << std::endl;
	if (a != b)
	 	std::cout << "Yes\n";
	else
	 	std::cout << "No\n";
	std::cout << OR << "B == C?" RESET << std::endl;
	if (b == c)
	 	std::cout << "Yes\n";
	else
	 	std::cout << "No\n";
	std::cout << std::endl;

	std::cout << OR << "=== TEST 6 and 7: + and * overload" << RESET << std::endl;
	std::cout << "A + B\n" << a + b << std::endl;
	std::cout << "B * C?\n" << b * c << std::endl;
	std::cout << std::endl;

	std::cout << OR << "=== TEST 8 and 9: ++ and -- overload" << RESET << std::endl;
	std::cout << "A: " << a << std::endl << "A++\n" << a++ << std::endl;
	std::cout << "B: " << b << std::endl << "B--\n" << b-- << std::endl;
	std::cout << std::endl;

	std::cout << OR << "=== TEST 10 and 11: min/max" << RESET << std::endl;
	std::cout << "Min between A & B?" << std::endl;
	Fixed& mini = Fixed::min(a, b);
	std::cout << mini;
	std::cout << std::endl;

	std::cout << "Max between B & C?" << std::endl;
	Fixed& maxi = Fixed::max(a, b);
	std::cout << maxi;
	std::cout << std::endl;
	std::cout << OR << "=== DESTRUCTORS" << RESET << std::endl;

}