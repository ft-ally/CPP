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

#include "phonebook.class.hpp"

int main()
{
	Phonebook	phonebook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT)";
		std::getline(std::cin, command);
		
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "Invalid command!" << std::endl 
				<< "Enter command (ADD, SEARCH, EXIT)" << std::endl;
		
	}
}