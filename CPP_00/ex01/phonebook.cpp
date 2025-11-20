/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/20 16:18:28 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <string>
#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
	oldest = 0;

}

void PhoneBook::add()
{
	contacts[oldest].addContact();
	if (count < 8)
		count++;
	oldest++;
	if (oldest == 8)
		oldest = 0;
	
}
void PhoneBook::printOverview()
{
	for (int i = 0; i < count; i++)
		contacts[i].displayContactOverview(i);
}

void printHeader()
{
	std::cout << "|" << std::setw(10) << "Index"
	<< "|" << std::setw(10) << "First Name"
	<< "|" << std::setw(10) << "Last Name"
	<< "|" << std::setw(10) << "Nickname"
	<< "|" << std::endl;
}
int getIndexNumber(int count)
{
	int input;
	std::string inputStr;

	while (1)
	{
		std::cout << "Select an index to display a contact: " << std::endl;
		if (!std::getline(std::cin, inputStr))
			break ;
		if (!isDigit(inputStr))
		{
			std::cout << "Error! Enter numbers only!" << std::endl;
			continue;
		}
		input = std::stoi(inputStr);
		if (input < 0 || input > count - 1)
		{
			std::cout << "Error! Enter index number from 0 to " << count - 1
			<< " \n";
		}
		else
			return (input);
	}
	return (-1);
}
void PhoneBook::printContact(int i)
{
	contacts[i].displayContactDetails();
}
void PhoneBook::search()
{
	int index;

	if (count == 0)
		std::cout << "No contacts yet.." << std::endl;
	else
	{
		printHeader();
		printOverview();
		index = getIndexNumber(count);
		if (index == -1)
			return ;
		printContact(index);
	}
}

