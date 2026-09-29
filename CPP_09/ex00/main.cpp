#include "BitcoinExchange.hpp"


#define BIT_DB "./data.csv"


int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error, must input database to compare from!" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange exchange;
		exchange.loadDataBase(BIT_DB);
		exchange.startExchange(argv[1]);
		return 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
