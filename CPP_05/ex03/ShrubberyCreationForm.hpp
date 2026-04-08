#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	std::string		_target;
	
	public:
	static const int SIGN = 145;
	static const int EXEC = 137;

	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	void action() const override;
	
};
#endif

