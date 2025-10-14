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

Zombie::Zombie()
{
	
}
Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " has gone to the light"
	<< std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(int i)
{
	std::cout << name << " " << i << ": BraiiiiiiinnnzzzZ..." 
			<< std::endl;
}