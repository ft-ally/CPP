
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "iostream"

#define RESET   "\033[0m"
#define MAG "\033[35m"
#define GRN "\033[32m"
#define RED "\033[31m"

int main()
{
	std::cout << MAG << " ========= FORM TESTS =========" << RESET << std::endl;
	Bureaucrat john("John", 150);
	Bureaucrat michael("Michael", 1);

	std::cout << MAG << " ========= Test 1: Form 1 =========" << RESET << std::endl;
	try
	{
		std::cout << "Form 1: Sign grade: 50, Execute grade: 75" << std::endl;
		Form form1("Form 1", 50, 75);
		std::cout << GRN << "Form 1 created successfully" << RESET << std::endl << form1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << MAG << " ========= Test 2: Form 2 - Grade Too High =========" << RESET << std::endl;
	std::cout << "Form 2: Sign grade: 0, Execute grade 50" << std::endl;
	try
	{
		Form form2("Form2", 0, 50);
		
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	

	std::cout << std::endl << std::endl;

	std::cout << MAG << " ========= Test 3: Form 3 - Grade Too Low =========" << RESET << std::endl;
	try
	{
		std::cout << "Form 3: Sign grade: 151, Execute grade: 50" << std::endl;
		Form form3("Form 3", 151, 50);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << MAG << " ========= Test 4: Form signed =========" << RESET << std::endl;
	try
	{
		Form form4("Form 4", 150, 100);
		std::cout << "Is Form 4 signed? " << RED << form4.getIsSigned() << RESET  << std::endl;
		john.signForm(form4);
		std::cout << "Is Form 4 signed " <<  GRN << form4.getIsSigned() << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << MAG << " ========= Test 5: Form not signed - grade too low =========" << RESET << std::endl;
	try
	{
		Form form5("Form 5", 10, 5);
		std::cout << "Is Form 5 signed? " << RED << form5.getIsSigned() << RESET  << std::endl;
		john.signForm(form5);
		std::cout << "Is Form 5 signed? " << RED << form5.getIsSigned() << RESET  << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << std::endl;
	
}