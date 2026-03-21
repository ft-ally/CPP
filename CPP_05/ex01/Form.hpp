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
		void beSigned(const Bureaucrat &b);
		
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

std::ostream& operator<<(std::ostream &os, const Form &obj);
#endif
