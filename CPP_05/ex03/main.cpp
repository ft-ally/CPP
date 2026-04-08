
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include "iostream"

#define RESET   "\033[0m"
#define MAG "\033[35m"
#define GRN "\033[32m"
#define RED "\033[31m"

int main()
{
	std::cout << MAG << " ==== TEST 1: Expected: Intern creates form" << RESET << std::endl;
	Intern randomIntern;
	AForm *forms[4];
	
	try
	{ 
		forms[0] = randomIntern.makeForm("shrubbery creation", "Bender");
		forms[1] = randomIntern.makeForm("robotomy request", "Bender");
		forms[2] = randomIntern.makeForm("presidential pardon", "Bender");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << std::endl << std::endl;
	std::cout << MAG << " ==== TEST 2: Expected: John signs and executes form" << RESET << std::endl;
	Bureaucrat john("John", 2);
	std::cout << john << std::endl;
	try
	{
		john.signAForm(*forms[1]);
		john.executeForm(*forms[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;
	std::cout << MAG << " ==== TEST 3: Expected: John cannot execute form without sign" << RESET << std::endl;
	try
	{
		john.executeForm(*forms[2]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;
	std::cout << MAG << " ==== TEST 4: Expected: Intern cannot create form" << RESET << std::endl;
	try
	{ 
		forms[3] = randomIntern.makeForm("bad request", "Bender");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl; 
	}
	for (int i = 0; i < 3; i++)
		delete forms[i];
}

