/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/10/02 16:30:42 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "contact.hpp"

Contact::Contact()
{

}

bool isDigit(std::string number)
{
	for (unsigned int i = 0; i < number.length(); i++)
	{
		if (!std::isdigit(number[i]))
			return (false);
	}
	return true;
}
std::string	getField(std::string str)
{
	std::string	input;
	if (str == "secret")
	{
		std::cout << "What is your darkest secret? ";
		std::getline(std::cin, input);
	}
	else
	{
		std::cout << "Enter your " << str << ": ";
		std::getline(std::cin, input);
	}
	if (input.length() == 0)
	{
		while (input.length() == 0)
		{
			std::cout << "Field cannot be empty!" << std::endl;
			std::cout << "Enter your " << str << ": ";
			std::getline(std::cin, input);
		}
	}
	if (str == "phone number" && !isDigit(input))
	{
		while (!isDigit(input))
		{
			std::cout << "ERROR: Invalid character detected" << std::endl;
			std::cout << "Enter your " << str << ": ";
			std::getline(std::cin, input);
		}
	}
	
	return (input);
}
int Contact::addContact()
{
	firstName = getField("first name");
	lastName = getField("last name");
	nickName = getField("nick name");
	phoneNumber = getField("phone number");
	darkestSecret = getField("secret");
	usleep(500000);
	std::cout << "Contact " << firstName << " successfully saved!" << std::endl;
	return (1);
}

std::string format(std::string field)
{
	if (field.length() > 10)
		return (field.substr(0,9) + ".");
	return (field);
}
void Contact::displayContactOverview(int i)
{
	std::cout << "|" << std::setw(10) << i
	<< "|" << std::setw(10) << format(firstName)
	<< "|" << std::setw(10) << format(lastName)
	<< "|" << std::setw(10) << format(nickName)
	<< "|" << std::endl;
}
void Contact::displayContactDetails()
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nick name: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}