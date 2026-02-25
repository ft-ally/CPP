
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define MAG "\033[35m"

int main()
{
	std::cout << MAG << " ========= TESTS =========" << RESET << std::endl;
	std::cout << "Initializing John with score of 150" << std::endl;
	Bureaucrat john("John", 150);
	std::cout << "Initializing Michael with score of 1" << std::endl;
	Bureaucrat michael("Michael", 1);
	std::cout << std::endl << std::endl;

	std::cout << MAG << " ========= Test 2: Invalid grade  =========" << RESET << std::endl;
	std::cout << "Initializing Richard with score of 0" << std::endl;
	Bureaucrat richard("Richard", 0);
	std::cout << "Initializing Joe with score of 151" << std::endl;
	Bureaucrat joe("Joe", 151);
	std::cout << std::endl << std::endl;

	std::cout << MAG << " ========= Test 3: getName =========" << RESET << std::endl;
	std::cout << "Name of suit1: " << john.getName() << std::endl;
	std::cout << "Name of suit2: " << michael.getName() << std::endl;
	std::cout << std::endl << std::endl;
	
	std::cout << MAG << " ========= Test 4: getGrade =========" << RESET << std::endl;
	std::cout << "John's initial grade: " << john.getGrade() << std::endl;
	std::cout << "Michael's initial grade: " << michael.getGrade() << std::endl;
	std::cout << std::endl << std::endl;
	
	std::cout << MAG << " ========= Test 5: Increment =========" << RESET << std::endl;
	std::cout << "***Incrementing John's grade***" << std::endl;
	john.incrementGrade();
	std::cout << "John's incremented grade: " << john.getGrade() << std::endl;

	std::cout << "***Incrementing Michael's grade***" << std::endl;
	michael.incrementGrade();
	std::cout << "Michael's incremented grade: " << michael.getGrade() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << MAG << " ========= Test 6: Decrement =========" << RESET << std::endl;
	std::cout << "***Decrementing John's grade***" << std::endl;
	john.decrementGrade();
	std::cout << "John's decremented grade: " << john.getGrade() << std::endl;

	std::cout << "***Decrementing Michael's grade***" << std::endl;
	michael.decrementGrade();
	std::cout << "Michael's decremented grade: " << michael.getGrade() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << MAG << " ========= Test 7:  << overload  =========" << RESET << std::endl;
	std::cout << john << std::endl;
	std::cout << michael << std::endl;
	std::cout << std::endl << std::endl;


	// std::cout << MAG << " ========= Test :  =========" << RESET << std::endl;
	// std::cout << std::endl << std::endl;

}