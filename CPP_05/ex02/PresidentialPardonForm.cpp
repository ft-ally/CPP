#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("Default presidential pardon form", SIGN, EXEC),
	_target("Default target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:AForm("Presidential Pardon Form", SIGN, EXEC),
	_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	:AForm(src), _target(src._target) {}
	
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action()
{
	std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}