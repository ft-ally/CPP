#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default shrubbery creation form", SIGN, EXEC),
	_target("Default target") {}
	
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("Shrubbery Creation Form", SIGN, EXEC), 
	_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		this->_target = src._target;
		AForm::operator=(src);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action()
{
	std::ofstream file;
	file.open(this->_target + "_shrubbery");
	if (file.is_open())
	{
		file <<
		"             ,@@@@@@@,\n"
		" 	  ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		"	,&%%&%&&%,@@@@@/@@@@@@,8888 88/8o\n"
		" ,%&%&&%&&%,@@@ @@@/@@@88 8888/88'\n"
		" %&&%&%&/%&&%@@ @@/ /@@@88888 88888'\n"
		" %&&%/ %&%%&&@@ V /@@' `88 8 `/88'\n"
		" `&% ` /%&'    |.|         |'|8'\n"
		"	  |o|       | |         | |\n"
		"     |.|       | |         | |\n"
		"    / ._\\//_/__/  , _//__\\/.  \\ _//__/_\n";
		file.close();
		std::cout << _target << "_shrubbery file created!" << std::endl;
	}
	else
		std::cout << "Error, could not open file" << std::endl;
}