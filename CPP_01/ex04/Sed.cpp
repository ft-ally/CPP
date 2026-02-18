/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:12:43 by aalombro          #+#    #+#             */
/*   Updated: 2026/02/18 12:13:27 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	replaceContent(std::ifstream &file, std::ofstream &newFile, std::string s1, std::string s2)
{
	std::string	line;
	size_t		pos;
	
	while (std::getline(file, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		newFile << line << "\n";
	}
}
int	handleFile(std::string fileName, std::string s1, std::string s2)
{
	std::ifstream	file;
	std::ofstream	newFile;
	
	file.open(fileName);
	if (!file)
	{
		std::cerr << "File error";
		return (0);
	}
	std::ifstream checkFile(fileName + ".replace");
	if (checkFile.good())
	{
		std::cerr << "Error: " << fileName << ".replace already exists!";
		checkFile.close();
		file.close();
		return (0);
	}
	checkFile.close();
	newFile.open(fileName + ".replace");
	if (!newFile)
	{
		std::cerr << "Error creating new file!";
		file.close();
		return (0);
	}
	replaceContent(file, newFile, s1, s2);
	file.close();
	newFile.close();
	return (1);
}
