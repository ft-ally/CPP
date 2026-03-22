
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("Default robotomy", SIGN, EXEC),
	_target("Default target") {}
	
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("Robotomy Request Form", SIGN, EXEC),
	_target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return (*this);
}

void RobotomyRequestForm::action()
{
	std::cout << "*drilling noises*" << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
		std::cout << _target << " was not successfully robotomized :(" << std::endl;
}