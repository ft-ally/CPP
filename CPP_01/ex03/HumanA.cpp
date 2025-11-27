/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 16:46:47 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	:name(name), weapon(weapon)
{

}

HumanA::~HumanA()
{
	std::cout << "Human A " << name << " has become death."
			<< std::endl;
}
void HumanA::attack()
{
	std::cout << name << " attacks with their "
			<< weapon.getType() << std::endl;
}