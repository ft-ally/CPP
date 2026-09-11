#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>

class BitcoinExchange
{
	std::map<std::string, float>	_db; //check if i need to template this or just use float

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &src);
		~BitcoinExchange();
	
		void readDataBase(const char *db);
		void printData();
		float calculate();
		void checkRates(const std::string &line);
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

void BitcoinExchange::readDataBase(const char *db) {
	//load the database
	//store it inside the map
}

void BitcoinExchange::checkRates(const std::string &line) {
	//process line by line
	std::string line;
	std::getline(file, line);
	
	while (std::getline(file, line)) {
		//validate the line - date format and amount
		//if validation passes, calculate -> look up rate in db
	}
}


#endif