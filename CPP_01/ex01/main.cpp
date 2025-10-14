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

#include "Zombie.hpp"

bool isDigit(std::string input)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]) && input[i] != '-')
			return (false);
	}
	return true;
}
int getValidCount()
{
	std::string input;
	long int longCount;
	int count;
	while (1)
	{
		std::cout << "How many zombies would you like to create? ";
		std::getline(std::cin, input);
		if (!isDigit(input))
		{
			std::cout << "Invalid char detected!\n";
			continue ;
		}
		longCount = std::stol(input);
		if (longCount <= 0)
		{
			std::cout << "Input error! Cannot create negative or NO zombies..\n";
			continue ;
		}
		else if (longCount >= 2147483648)
		{
			std::cout << "ARE YOU TRYING TO CRASH ME!? Pls. Input a regular int\n";
			continue ;
		}
		else
		{
			count = std::stoi(input);
			return (count);
		}
	}
	return (count);
}
int main()
{
	std::string input;
	int count;
	count = getValidCount();
	std::cout << "And what should we call them? ";
	std::getline(std::cin, input);
	std::cout << "Creating a horde of " << input << " zombies...\n";
	Zombie *horde = zombieHorde(count, input);
	delete[] horde;
	return (0);
}