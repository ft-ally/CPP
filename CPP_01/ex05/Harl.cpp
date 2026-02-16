/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:26:47 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 18:55:56 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	std::cout << BLUE << ">>>>>Welcome to Harldonalds, how may we help you today?<<<<<\n" << RESET;
}

Harl::~Harl()
{
	std::cout << BLUE << ">>>>>Thank you for coming to Harldonalds, goodbyeee..... <<<<<\n" << RESET;
}

void Harl::debug(void)
{
	std::cout << GREEN << "I love having extra bacon for my" << 
		"7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << RESET;
}

void Harl::info(void)
{
	std::cout << YELLOW << "I cannot believe adding extra bacon costs more money.\n" <<
	 "You did not put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RESET;
}

void Harl::warning(void)
{
	std::cout << ORANGE "I think I deserve to have some extra bacon for free.\n" <<
		"I’ve been coming for years, whereas you started working here just last month.\n" << RESET;
}

void Harl::error(void)
{
	std::cout << RED << "This is unacceptable!!!!! I want to speak to the manager now.\n" << RESET;
}

void Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
}
