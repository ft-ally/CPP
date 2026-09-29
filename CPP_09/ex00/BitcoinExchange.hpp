#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cmath>

#define MIN_YEAR 2009

class BitcoinExchange
{
	std::map<std::string, double>	_db;
	std::string						_currentDate;
	double							_currentUnits;
	

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &src);
		~BitcoinExchange();
	
		void loadDataBase(const char *db);
		void parseInput(std::string line);
		void pushToOutput();
		void startExchange(char *inputFile);
};

#endif