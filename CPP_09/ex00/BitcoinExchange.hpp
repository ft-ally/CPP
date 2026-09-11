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
	
		void loadDataBase(const char *db);
		void printData();
		float calculate();
		void checkRates(char *inputFile);
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
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file\n";
		exit(1);
	}
	std::string line;
	std::getline(file, line);
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

static int validateDate(std::string date) {
	
}

void BitcoinExchange::checkRates(char *inputFile) {
	std::ifstream file(inputFile);
	if (!file.is_open()) {
		std::cout << "Error, must input database to compare from!" << std::endl;
		exit(1);
	}
	std::string line;
	std::getline(file, line);

	size_t pos = line.find(" | ");
	if (pos == std::string::npos) {
		std::cout << "Error, bad input: " << line << "\n";
		file.close();
		return;
	}

	std::string date = line.substr(0, pos);
	float units = std::stof(line.substr(pos, 3));
	
	if (!validateDate(date)) {
		std::cout << "Error: bad date input: " << line << '\n';
		file.close();
		return;
	}
}
	//process line by line
	//validate the line - date format and amount
	//if validation passes, calculate -> look up rate in db

#endif