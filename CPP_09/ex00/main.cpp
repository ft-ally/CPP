#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

#define BIT_DB "./data.csv"


int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error, must input database to compare from!" << std::endl;
		return 1;
	}
	BitcoinExchange exchange;
	exchange.loadDataBase(BIT_DB);
	exchange.checkRates(argv[1]);
	return 0;
}


//in main - take the input file
//validate argc =2, file perm, file open
//create the object with the db
//---validate db file -check file perm, file open 
//load data - get the database and save it to map
//--parse the data given, separate date, input
//---validate leap year, check for 30/31, repeating dates, wrong dates

//in main, using getline -
// parse the date and amount - use mktime()?

//https://stackoverflow.com/questions/9436697/c-check-if-a-date-is-valid
//calculate - using std::toupper? to get the matching or latest date
// --check the data given, aka compare it to database loaded
//call print to print 
//print the data to terminal