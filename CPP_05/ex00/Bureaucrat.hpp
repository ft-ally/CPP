#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat{
	private:
	const std::string _name;
	int _grade;

	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat&operator=(const Bureaucrat &src);


	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
	
	};
	class GradeTooLowException
	{

	};

};

std::ostream& operator<<(std::ostream& str, const Bureaucrat& obj);

#endif

//#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	std::cout << "Parameter constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Deconstructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Copy constructor called\n";
	this->_name = src._name;
	this->_grade = src._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_grade = src._grade;
	}
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& str, const Bureaucrat& obj)
{
	
}
