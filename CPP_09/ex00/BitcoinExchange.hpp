#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <stdexcept>
#include <iostream>
#include <fstream>

#define MIN_YEAR 2009

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
	//add validation here too or nah?
}

void BitcoinExchange::parseInput(std::string line) {
	size_t pos = line.find(" | ");
	if (pos == std::string::npos)
		throw std::runtime_error("Error, bad input: " + line);

	_currentDate = line.substr(0, pos);
	_currentUnits = std::stof(line.substr(pos, 3));
}

static void splitDate(std::string _currentDate, std::string &y, std::string &m, std::string &d) {
	if (_currentDate.size() != 10)
		throw std::runtime_error("Error, bad date input => " + _currentDate);

	size_t firstSep = _currentDate.find("-");
	if (firstSep == std::string::npos)
		throw std::runtime_error("Error, bad date format => " + _currentDate);

	size_t secondSep = _currentDate.find("-", firstSep + 1);
	if (secondSep == std::string::npos)
		throw std::runtime_error("Error, bad date format => " + _currentDate);

	y = _currentDate.substr(0, firstSep);
	m = _currentDate.substr(firstSep + 1, secondSep - firstSep - 1);
	d = _currentDate.substr(secondSep + 1);
}

static void checkDate(std::string currentDate, std::string yStr, std::string mStr, std::string dStr) {
	int year = std::stoi(yStr);
	int month = std::stoi(mStr);
	int date = std::stoi(dStr);
	
	if (year < MIN_YEAR)
		throw std::runtime_error("Error, BTC did not exist yet => " + currentDate);
	if (year > 2026)
		throw std::runtime_error("Error, date too far in the future => " + currentDate);
	if (month < 1 || month > 12)
		throw std::runtime_error("Error, bad date format => " + currentDate);
	if (date < 1 || date > 31)
		throw std::runtime_error("Error, bad date format => " + currentDate);
	if (month == 2) {
		bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
		if ((leap && date > 29) || (!leap && date > 28))
			throw std::runtime_error("Error, bad date format => " + currentDate);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 12) {
		if (date > 30)
			throw std::runtime_error("Error, bad date format => " + currentDate);
	}
}

static void validateDate(std::string _currentDate) {
	std::string year, month, day;
	splitDate(_currentDate, year, month, day);
	checkDate(_currentDate, year, month, day);
}


static void validateUnits(float _currentUnits) {
	
}

void BitcoinExchange::pushToOutput() {
	//if there is no current date, go to the one before
	//also check the result is not overflowing
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