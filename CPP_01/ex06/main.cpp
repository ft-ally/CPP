/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:26:22 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 19:38:16 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl	harl;
	
	if (argc == 1)
		std::cout << "What? Nothing to say? Pick DEBUG, INFO, WARNING, OR ERROR.";
	else
	{
		std::string complaint = argv[1];
		harl.complain(complaint);
	}

}