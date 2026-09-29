#include "BitcoinExchange.hpp"



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
		validateDate(date);
		double rate = stod(line.substr(pos + 1));
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

static void validateDate(const std::string& dateStr) {
	std::istringstream ss(dateStr);
	int year, month, day;
	char dash1, dash2;
	
	ss >> std::noskipws;
	
	if (!(ss >> year >> dash1 >> month >> dash2 >> day))
		throw std::runtime_error("Error, bad date format => " + dateStr);
	
	if (dash1 != '-' || dash2 != '-')
		throw std::runtime_error("Error, bad date format => " + dateStr);
	
	char leftover;
	if (ss >> leftover)
		throw std::runtime_error("Error, bad date format => " + dateStr);
	
	try {
		auto date = std::chrono::year{year} / std::chrono::month{static_cast<unsigned>(month)} / std::chrono::day{static_cast<unsigned>(day)};
		if (!date.ok())
			throw std::runtime_error("Error, bad date format => " + dateStr);
	}
	catch (const std::exception&) {
		throw std::runtime_error("Error, bad date format => " + dateStr);
	}
}

static void validateUnits(double units, std::string currentDate) {
	std::string line = currentDate + " | " + std::to_string(units);
	if (units < 0)
		throw std::runtime_error("Error, not a positive number => " + line);

	if (units == 0)
		throw std::runtime_error("Error, not a positive number => " + line);

	if (units > 1000000) // limit for btc
		throw std::runtime_error("Error, too large a number => " + line);
}

void BitcoinExchange::pushToOutput() {
	std::string line = _currentDate + " | " + std::to_string(_currentUnits);

	auto it = _db.find(_currentDate);
	if (it == _db.end()) {
		it = _db.lower_bound(_currentDate);
		if (it == _db.begin())
			throw std::runtime_error("Error: date too early => " + line);
		--it;
	}

	double result = _currentUnits * it->second;
	if (std::isnan(result) || std::isinf(result))
		throw std::runtime_error("Error: result overflow => " + line);

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
			validateUnits(_currentUnits, _currentDate);
			pushToOutput();
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			continue;
		}
	}
}
