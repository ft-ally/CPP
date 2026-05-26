#include "ScalarConverter.hpp"
#include <iomanip>

int getType(const std::string &str)
{
	int		len = str.length();
	bool	digit = false;
	int		dot = 0;

	if (len == 0)
		return NONE;
	if (len == 1 && isprint(str[0]) && !isdigit(str[0]))
		return CHAR;
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan" || str == "nanf")
		return PSEUDO;
	if (str[len - 1] == 'f' || str[len - 1] == 'F')
		return FLOAT;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '.')
			dot++;
	}
	if (dot > 1)
		return NONE;
	if (dot == 1)
		return DOUBLE;
	for (int i = 0; i < len; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (isdigit(str[i]))
			digit = true;
		else
			return NONE;
	}
	if (digit)
		return INT;
	else
		return NONE;
}

void Conversions::printConversion()
{
	if (std::isnan(f) || std::isinf(f) || std::isnan(d) || std::isinf(d))
	{
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl;
	}
	else if (NonDisplayable)
	{
		std::cout << "char: Non displayable" << std::endl
		<< "int: " << i << std::endl;
	}
	else
	{
		std::cout << "char: " << c << std::endl 
		<< "int: " << i << std::endl;
	}
	std::cout << "float: " <<  std::fixed << std::setprecision(1) << f << "f" << std::endl <<
	"double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void outputNonDisplayable(Conversions &conv)
{
	conv.NonDisplayable = true;
	conv.i = 0;
	conv.d = 0.0;
	conv.f = 0.0f;
}

void ScalarConverter::convert(const std::string &str)
{
	int type = getType(str);
	Conversions conv;
	switch (type)
	{
		case CHAR:
			convertChar(str, conv);
			break;
		case INT:
			convertInt(str, conv);
			break;
		case FLOAT:
			convertFloat(str, conv);
			break;
		case DOUBLE:
			convertDouble(str, conv);
			break;
		case PSEUDO:
			convertPseudo(str, conv);
			break;
		case NONE:
			outputNonDisplayable(conv);
			break;
	}
	conv.printConversion();
}
