#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern 
{
	public:
	Intern();
	~Intern();
	Intern(const Intern &src);
	Intern& operator=(const Intern &src);
	AForm* makeForm(const std::string &formName, const std::string &target);
	
	class FormNotFoundException : public std::exception
	{
		public:
		const char* what() const noexcept override;
	};
};

#endif