#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	:_name("Default"), _signGrade(75), _executeGrade(75), _isSigned(false) {}

AForm::AForm(std::string name, int signGrade, int executeGrade)
	:_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false) 
{
	if (_signGrade < MAX_GRADE || _executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_signGrade > MIN_GRADE || _executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}
	
AForm::~AForm() {}

AForm::AForm(const AForm &src)
	:_name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade), _isSigned(src._isSigned) {};

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		_isSigned = src._isSigned;
	return *this;
}

const std::string AForm::getName() const { return _name; }

int AForm::getSignGrade() const { return _signGrade; }

int AForm::getExecuteGrade() const { return _executeGrade; }

bool AForm::getIsSigned() const { return _isSigned; }

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw (GradeTooLowException());
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("AForm grade too high! Highest grade is 1");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("AForm grade too low! Lowest grade is 150");
}

std::ostream& operator<<(std::ostream &os, const AForm &AForm)
{
	os << "AForm name: " << AForm.getName() << std::endl
		<< "Sign grade: " << AForm.getSignGrade() << std::endl
		<< "Execute grade: " << AForm.getExecuteGrade() << std::endl
		<< "Signed: " << (AForm.getIsSigned() ? "Yes" : "No") << std::endl;
	return os;
}