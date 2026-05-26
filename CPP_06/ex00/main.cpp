
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "Error: no input" << std::endl;
	else if (argc > 2)
		std::cout << "Error: too many arguments" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
}