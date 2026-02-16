/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 13:55:10 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:name(name), weapon(nullptr)
{
	
}

HumanB::~HumanB()
{
	std::cout << RED<< "Human B " << name << " has become death."
			<< std::endl << RESET;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
void HumanB::attack()
{
	if (weapon)
	{
		std::cout << MAGENTA << name << " attacks with their "
			<< weapon->getType() << std::endl << RESET;
	}
	else
		std::cout << MAGENTA << name << " attacks with their bare hands!!" << std::endl << RESET;
}