
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "iostream"

#define RESET   "\033[0m"
#define MAG "\033[35m"
#define GRN "\033[32m"
#define RED "\033[31m"

int main()
{
	/*Initializing forms*/
	
	ShrubberyCreationForm shrubForm("Shrubbie");
	RobotomyRequestForm roboForm("Robbie");
	PresidentialPardonForm presForm("Pressie");
	
	std::cout << MAG << " ==== TEST 1: Expected: Can sign, can execute ====" << RESET << std::endl;
	Bureaucrat boss("Boss Mark", 1);
	std::cout << boss << std::endl << std::endl;
	try
	{
		boss.signAForm(shrubForm);
		boss.signAForm(roboForm);
		boss.signAForm(presForm);
		std::cout << std::endl;
		boss.executeForm(shrubForm);
		boss.executeForm(roboForm);
		boss.executeForm(presForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << MAG << " ==== Test 2: Expected: can sign and execute Shrub but not Robo and Pres ====" << RESET << std::endl;
	
	Bureaucrat regularEmployee("RegularJohn", 136);
	std::cout << regularEmployee << std::endl << std::endl;
	try
	{ 
		regularEmployee.signAForm(shrubForm);
		regularEmployee.signAForm(roboForm);
		regularEmployee.signAForm(presForm);
		std::cout << std::endl;
		regularEmployee.executeForm(shrubForm);
		regularEmployee.executeForm(roboForm);
		regularEmployee.executeForm(presForm);
	}
	catch (std::exception &e)
	{	std::cout << e.what() << std::endl; }
	std::cout << MAG << " ==== Test 3: Expected: Form not signed exception ====" << RESET << std::endl;
	
	Bureaucrat anotherEmployee("AnotherJohn", 70);
	RobotomyRequestForm newRoboRequest("Flora");
	std::cout << anotherEmployee << std::endl << std::endl;
	try
	{ 
		regularEmployee.executeForm(newRoboRequest);
	}
	catch (std::exception &e)
	{	std::cout << e.what() << std::endl; }
}

