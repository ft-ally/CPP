/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 16:25:23 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

bool isDigit(std::string input)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	return true;
}
int getValidCount()
{
	std::string input;
	long long int longCount;
	int count = 0;

	while (1)
	{
		std::cout << "How many zombies would you like to create? ";
		if (!std::getline(std::cin, input))
			exit (0);
		if (input.length() == 0)
			continue ;
		if (!isDigit(input))
		{
			std::cout << "Invalid input/char detected!\n";
			continue ;
		}
		try
		{
			longCount = std::stoll(input);
		}
		catch (const std::out_of_range &e)
		{
			std::cout << "ARE YOU TRYING TO CRASH ME!? Pls. use a reasonable number.\n";
			continue ;
		}
		if (longCount <= 0)
		{
			std::cout << "Input error! Cannot create NO zombies..\n";
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
	while (1)
	{
		std::cout << "And what should we call them? ";
		if (!std::getline(std::cin, input))
			exit(0);
		if (input.length() == 0)
			continue ;
		else
			break ;
	}
	std::cout << "Creating a horde of " << input << " zombies...\n";
	Zombie *horde = zombieHorde(count, input);
	delete[] horde;
	return (0);
}