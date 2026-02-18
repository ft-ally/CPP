/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:12:43 by aalombro          #+#    #+#             */
/*   Updated: 2026/02/18 12:13:41 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
	std::string	fileName;
	std::string	s1;
	std::string	s2;
	
	if (argc != 4)
	{
		std::cerr << "Parameter error! Add the filename, string to replace, string to replace with";
		return (1);
	}
	fileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (!handleFile(fileName, s1, s2))
		return (1);
	return (0);
}

//turn cat into dog, 123 to XXX, o to =