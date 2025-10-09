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

#include "phonebook.hpp"
#include <unistd.h>

void	display_boot_message()
{
	std::cout << "doop doop doop (startup music)" << std::endl;
	usleep(500000);
	std::cout << "Welcome to your very own PhoneBook" << std::endl << std::endl;
	usleep(800000);
	std::cout << "ADD: Add up to 8 contacts!" << std::endl << "When 8 contacts are exceeded, ";
	std::cout << "newest will replace the oldest!" << std::endl;
	usleep(900000);
	std::cout << "SEARCH: Search for a contact"<<std::endl;
	usleep(800000);
	std::cout << "EXIT: Exit the program, contacts will be deleted" << std::endl << std::endl;

}
int main()
{
	Phonebook	phonebook;
	std::string	command;

	//display_boot_message();
	while (1)
	{
		usleep(800000);
		std::cout << "What would you like to do? [ADD/SEARCH/EXIT]" << std::endl;
		std::getline(std::cin, command);
		
		if (command == "EXIT")
		{
			std::cout << "Contacts will be deleted upon exit. Are you sure? [Y/N]" << std::endl;
			std::getline(std::cin, command);
			if (command == "Y" || command == "y")
				break ;
			else
				continue ;
		}
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else
			continue ;
	}
	std::cout << "Contacts deleted" << std::endl;
	std::cout << "Goodbye forever!";
	return(1);
}