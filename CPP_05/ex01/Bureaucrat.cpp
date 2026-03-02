#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:_name("Default"), _grade(75) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:_name(name), _grade(grade)
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	:_name(src._name), _grade(src._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
