/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:51:09 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/02 17:20:43 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	
	public:
		Contact();
		void addContact();
		void displayContact(void);
		void displayRow(void);
		bool isEmpty(void);
};

class Phonebook
{
	Contact	contacts[8];
	int		count;
	int		oldest;
	public:
		Phonebook();
		void add(void);
		void search(void);
};

Phonebook::Phonebook()
{
	count = 0;
	oldest = 0;

}
void Phonebook::add()
{
	contacts[oldest].addContact();
	if (count < 8)
	{
		count++;
		oldest++;
	}
	if (oldest == 8)
		oldest = 0;
	
}

void Contact::addContact()
{
	std::cout << "Enter your first name:";
		std::getline(std::cin, firstName);	
	if (firstName.length() == 0)
	{
		std::cout << "TELL ME YOUR FIRST NAME!:";
		std::getline(std::cin, firstName);	
	}
	std::cout << "Enter your last name:";
		std::getline(std::cin, lastName);
	if (lastName.length() == 0)
	{
		std::cout << "TELL ME YOUR LAST NAME!:";
		std::getline(std::cin, lastName);
	}
	std::cout << "Enter your nick name:";
		std::getline(std::cin, nickName);
	if (nickName.length() == 0)
	{
		std::cout << "No nickname huh? Alright then, ur new nickname is Gilbert";
		nickName = "Gilbert";
	}
	std::cout << "Enter your phone number:";
		std::getline(std::cin, phoneNumber);
	if (nickName.length() == 0)
	{
		std::cout << "Gimme ittttt";
		std::getline(std::cin, phoneNumber);
	}
	std::cout << "What is your deepest darkest most awesome secret?";
	std::getline(std::cin, darkestSecret);	
}