/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 13:55:07 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define ORANGE  "\033[38;5;208m"

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	std::string name;
	Weapon &weapon; //must be initialized, cannot be empty
	
	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif