#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm 
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_executeGrade;
		bool				_isSigned;
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		
		const int MAX_GRADE = 1;
		const int MIN_GRADE = 150;
		const std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat &b);
		virtual void action() = 0;
		
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

std::ostream& operator<<(std::ostream &os, const AForm &obj);
#endif
