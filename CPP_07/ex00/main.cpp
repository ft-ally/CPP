#include "Colors.hpp"
#include "whatever.hpp"

void printExpected()
{
	std::cout 
	<< "a = 3, b = 2" << std::endl
	<< "min(a, b) = 2" << std::endl
	<< "max(a, b) = 3" << std::endl
	<< "c = chaine2, d = chaine1" << std::endl
	<< "min(c, d) = chaine1" << std::endl
	<< "max(c, d) = chaine2" << std::endl;
}

int main()
{
	std::cout << GREEN << "=====EXPECTED=====" <<std::endl << RESET;
	printExpected();
	
	std::cout << std::endl << GREEN << "=====ACTUAL=====" <<std::endl << RESET;
	
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	std::cout << std::endl << GREEN << "=====OTHER TESTS=====" <<std::endl << std::endl << RESET;
	int x = 11;
	int y = 10;
	std::cout << "x = " << x << std::endl << "y = " << y <<std::endl; 
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl << std::endl;
	std:: cout << "Calling swap... " << std::endl;
	::swap(x, y);
	std::cout << "x = " << x << std::endl << "y = " << y <<std::endl; 

	std::cout << std::endl << "==========" <<std::endl << std::endl;

	float f1 = 3.14f;
	float f2 = 2.71f;
	std::cout << "f1 = " << f1 << std::endl << "f2 = " << f2 <<std::endl ;
	std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
	std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl << std::endl;
	std:: cout << "Calling swap... " << std::endl;
	::swap(f1, f2);
	std::cout << "f1 = " << f1 << std::endl << "f2 = " << f2 <<std::endl ; 

	std::cout << std::endl << "==========" <<std::endl << std::endl;
	
	std::string s1 = "apple";
	std::string s2 = "banana";
	std::cout << "s1 = " << s1 << std::endl << "s2 = " << s2 <<std::endl;

	std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
	std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;
	std:: cout << "Calling swap... " << std::endl;
	::swap(s1, s2);
	std::cout << "s1 = " << s1 << std::endl << "s2 = " << s2 <<std::endl << std::endl; 

	
	return 0;
}