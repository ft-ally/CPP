#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
	
	const static int MIN_GRADE = 150;
	const static int MAX_GRADE = 1;
	
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

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
