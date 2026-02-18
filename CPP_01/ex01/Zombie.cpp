/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2026/02/18 12:04:14 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	
}
Zombie::~Zombie()
{
	std::cout << CYAN << "Zombie " << name << " has gone to the light" << RESET
	<< std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(int i)
{
	std::cout << MAGENTA << name << " " << i << ": BraiiiiiiinnnzzzZ..." 
			<< RESET << std::endl;
}