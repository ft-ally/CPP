
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
	// std::cout << MAG << " ===== AForm Test - cannot instantiate ====" << RESET << std::endl;
	// AForm form();
	
	std::cout << MAG << " ==== Test 1: Shrubbery ====" << RESET << std::endl;
	ShrubberyCreationForm shrub("Helga");
	shrub.action();
	std::cout << std::endl;
	
	std::cout << MAG << " ==== Test 2: Robotomy ====" << RESET << std::endl;
	RobotomyRequestForm rob("David");
	rob.action();
	std::cout << std::endl << std::endl;
	
	std::cout << MAG << " ==== Test 3: Presidential Pardon ====" << RESET << std::endl;
	PresidentialPardonForm pard("Pardy");
	pard.action();
	std::cout << std::endl << std::endl;
	
}


/*
Make a virtual function in Aform that does something
activity? action? special move?
Shrub - sign and exec to 145 137
action: make a file with tree

Robotomy - initialize 72 45
action rand % 2 == 0 

president - 25 5
stdcout pardoned

Add execute to Form
->Create notsigned exception
->Check if form is signed
->Check if grade of bureaucrat trying to execute form is high enough
--->kinda like this bureaucrat.grade > gradetoexecuteform
->Create executor grade not high enough exception
Else do the action

Add executeForm to bureaucratclass
i guess it calls execute
print bureaucrat executed form
catch the exception


*/