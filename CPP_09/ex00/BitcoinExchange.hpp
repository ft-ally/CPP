#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <stdexcept>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
	std::map<std::string, float>	_db;
	std::string						_currentDate;
	float							_currentUnits;
	

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
	
BitcoinExchange::BitcoinExchange() : _db() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src)
		_db = src._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDataBase(const char *db) {
	std::ifstream file(db);
	if (!file.is_open())
		throw std::runtime_error("Error, could not open database file\n");
	std::string line;
	if (!std::getline(file, line)) 
		throw std::runtime_error("Error, empty database file\n");
	while (std::getline(file, line)) {
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		float rate = stof(line.substr(pos + 1));
		_db[date] = rate;
	}
	file.close();
}

void BitcoinExchange::parseInput(std::string line) {
	size_t pos = line.find(" | ");
	if (pos == std::string::npos)
		throw std::runtime_error("Error, bad input: " + line);

	_currentDate = line.substr(0, pos);
	_currentUnits = std::stof(line.substr(pos, 3));
}


static void validateDate(std::string _currentDate) {
	
}


static void validateUnits(float _currentUnits) {
	
}

void BitcoinExchange::pushToOutput() {
	float result = _currentUnits * _db[_currentDate];
	std::cout << _currentDate << " => "
		<< _currentUnits << " = " 
		<< result
		<< "\n";
}

void BitcoinExchange::startExchange(char *inputFile) {
	std::ifstream file(inputFile);
	if (!file.is_open())
		throw std::runtime_error("Error, could not open input file\n");

	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error, empty input file\n");
	
	while (std::getline(file, line)) {
		try {
			parseInput(line);
			validateDate(_currentDate);
			validateUnits(_currentUnits);
			pushToOutput();
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			continue;
		}
	}
}
	//process line by line
	//validate the line - date format and amount
	//if validation passes, calculate -> look up rate in db

#endif