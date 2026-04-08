#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	std::string		_target;

	public:
	static const int SIGN = 25;
	static const int EXEC = 5;

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	void action() const override;
};

#endif