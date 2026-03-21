#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	:_name("Default"), _signGrade(75), _executeGrade(75), _isSigned(false) {}

Form::Form(std::string name, int signGrade, int executeGrade)
	:_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false) 
{
	if (_signGrade < MAX_GRADE || _executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_signGrade > MIN_GRADE || _executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}
	
Form::~Form() {}

Form::Form(const Form &src)
	:_name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade), _isSigned(src._isSigned) {};

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		_isSigned = src._isSigned;
	return *this;
}

const std::string Form::getName() const { return _name; }

int Form::getSignGrade() const { return _signGrade; }

int Form::getExecuteGrade() const { return _executeGrade; }

bool Form::getIsSigned() const { return _isSigned; }

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw (GradeTooLowException());
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Form grade too high! Highest grade is 1");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Form grade too low! Lowest grade is 150");
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << std::endl
		<< "Sign grade: " << form.getSignGrade() << std::endl
		<< "Execute grade: " << form.getExecuteGrade() << std::endl
		<< "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	return os;
}