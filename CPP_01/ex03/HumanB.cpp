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

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:name(name), weapon(nullptr)
{
	
}

HumanB::~HumanB()
{
	std::cout << "Human B " << name << " has become death."
			<< std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
void HumanB::attack()
{
	if (weapon)
	{
		std::cout << name << " attacks with their "
			<< weapon->getType() << std::endl;
	}
	else
		std::cout << name << " attacks with their bare hands!!" << std::endl;
}