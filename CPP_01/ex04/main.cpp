/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalombro <aalombro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:12:43 by aalombro          #+#    #+#             */
/*   Updated: 2025/11/27 18:22:54 by aalombro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

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