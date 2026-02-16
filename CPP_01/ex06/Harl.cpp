/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:26:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 19:32:54 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << GREEN << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my" << 
		"7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << RESET;
}

void Harl::info(void)
{
	std::cout << YELLOW << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money!!! " <<
	 "You did not put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RESET;
}

void Harl::warning(void)
{
	std::cout << ORANGE << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free! " <<
		"I’ve been coming for years, whereas you started working here just last month!!!\n" << RESET;
}

void Harl::error(void)
{
	std::cout << RED << "[ ERROR ]\n";
	std::cout << "This is UNACCEPTABLE!!!!! I want to speak to the manager now!!!!!\n" << RESET;
}

void Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
