
#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

int getIndex(const std::string &formName)
{
	std::string form[3] = { 
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == form[i])
			return i;
	}
	throw (Intern::FormNotFoundException());
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	int formNumber = getIndex(formName);
	switch (formNumber)
	{
		case 0: 
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		case 1:
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case 2:
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (new PresidentialPardonForm(target));
		}
	}
	return (NULL);
}

const char* Intern::FormNotFoundException::what() const noexcept
{
	return ("Intern could not make that form");
}
