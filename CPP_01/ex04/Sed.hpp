#ifndef SED_HPP
#define SED_HPP


#include <iostream>
#include <fstream>

void	replaceContent(std::ifstream &file, std::ofstream &newFile, std::string s1, std::string s2);
int		handleFile(std::string fileName, std::string s1, std::string s2);


#endif