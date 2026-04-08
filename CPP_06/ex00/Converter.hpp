#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include "string"

class Converter {

	public:
	static void convert(const std::string &str);
	Converter();
	Converter(char const &c);
	Converter(const std::string &str);
	Converter(int i);
	Converter(float f);
	Converter(double d);
	virtual ~Converter();
	Converter(const Converter &src);
	Converter& operator=(const Converter &src);

	int toInt(char const &c);
	int toInt(const std::string &str);
	int toInt(float f);
	int toInt(float d);
	
};

/*
./convert 20
Main receives
Converter trial(*argv[1]);


*/
#endif