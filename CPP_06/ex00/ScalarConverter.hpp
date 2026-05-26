#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include "string"
#include "iostream"
#include <stdexcept>
#include <cmath>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	NONE
};

struct Conversions {
	char		c;
	int			i;
	float		f;
	double		d;
	bool		NonDisplayable;
	void		printConversion();
};

class ScalarConverter {

	public:
	ScalarConverter() = delete;
	~ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter &src) = delete;
	ScalarConverter& operator=(const ScalarConverter &src) = delete;
	static void convert(const std::string &str);
};

int			getType(const std::string &str);
void	outputNonDisplayable(Conversions &conv);
void	convertChar(const std::string &str, Conversions &conv);
void	convertInt(const std::string &str, Conversions &conv);
void	convertFloat(const std::string &str, Conversions &conv);
void	convertDouble(const std::string &str, Conversions &conv);
void	convertPseudo(const std::string &str, Conversions &conv);


#endif