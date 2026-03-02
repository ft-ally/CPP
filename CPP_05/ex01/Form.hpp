#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form 
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_isSigned;
	public:
		Form();
		~Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		
		const int MAX_GRADE = 1;
		const int MIN_GRADE = 150;
		const std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat &bureaucrat);
		
		class GradeTooHighException : public std::exception
		{
			public:
			const char *what() const noexcept override;
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
			const char *what() const noexcept override;
		};
	
};

std::ostream& operator<<(std::ostream os, const Form &obj);
#endif

//#include "Form.hpp"
Form::Form()
	:_name("Default"), _isSigned(0), _executeGrade(75), _signGrade(75) {}

Form::Form(std::string name, int signGrade, int executeGrade)
	:_name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(0) 
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

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Form grade too high! Highest grade is 1");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Form grade too low! Lowest grade is 150");
}

std::ostream& operator<<(std::ostream os, Form form)
{
	os << "Form name: " << form.getName() << std::endl
		<< "Sign grade: " << form.getSignGrade() << std::endl
		<< "Execute grade" << form.getExecuteGrade() << std::endl
		<< "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	return os;
}