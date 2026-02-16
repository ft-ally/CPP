/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:30:41 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 13:54:58 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << GREEN << "Memory address of string variable: " << &str << "\n" << RESET;
	std::cout << BLUE << "Memory address held by stringPTR: " << stringPTR << "\n" << RESET;
	std::cout << MAGENTA << "Memory address held by stringREF: " << &stringREF << RESET << std::endl << std::endl;

	std::cout << GREEN << "Value of string variable: " << str << "\n" << RESET;
	std::cout << BLUE << "Value pointed to by stringPTR: " << *stringPTR << "\n" << RESET;
	std::cout << MAGENTA << "Value pointed to by stringREF: " << stringREF << "\n" << RESET;

}