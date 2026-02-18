/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2026/02/18 12:09:25 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <string>
#include <iostream>

int main()
{
	Weapon club = Weapon("crude spiked club");
	//	bob.attack();
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	
	Weapon hammer = Weapon("crude spiked club");

	HumanB jim("Jim");
	//jim.attack(); //no weapon
	
	jim.setWeapon(hammer);
	jim.attack();
	hammer.setType("some other type of club");
	jim.attack();
}