#include "ScalarConverter.hpp"

void convertChar(const std::string &str, Conversions &conv)
{
	if (!std::isprint(str[0]))
		return outputNonDisplayable(conv);
	conv.c = str[0];
	conv.i = static_cast<int>(str[0]);
	conv.f = static_cast<float>(str[0]);
	conv.d = static_cast<double>(str[0]);
	conv.NonDisplayable = false;
}

void convertInt(const std::string &str, Conversions &conv)
{
	try 
	{
		conv.i = std::stoi(str);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		outputNonDisplayable(conv);
		return;
	}
	if (conv.i >= 0 && conv.i <= 127 && std::isprint(conv.i))
	{
		conv.c = static_cast<char>(conv.i);
		conv.NonDisplayable = false;
	}
	else
		conv.NonDisplayable = true;
	conv.f = static_cast<float>(conv.i);
	conv.d = static_cast<double>(conv.i);
}

void convertFloat(const std::string &str, Conversions &conv)
{
	try
	{
		conv.f = std::stof(str);
		if (std::isnan(conv.f) || std::isinf(conv.f))
			outputNonDisplayable(conv);
		else
		{
			conv.i = static_cast<int>(conv.f);
			if (conv.i >= 0 && conv.i <= 127 && std::isprint(conv.i))
				conv.c = static_cast<char>(conv.i);
			else
				conv.NonDisplayable = true;
		}
		conv.d = static_cast<double>(conv.f);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		outputNonDisplayable(conv);
	}
}

void convertDouble(const std::string &str, Conversions &conv)
{
	try
	{
		conv.d = std::stod(str);
		if (std::isnan(conv.d) || std::isinf(conv.d))
			outputNonDisplayable(conv);
		else
		{
			conv.i = static_cast<int>(conv.d);
			if (conv.i >= 0 && conv.i <= 127 && std::isprint(conv.i))
				conv.c = static_cast<char>(conv.i);
			else
				conv.NonDisplayable = true;
		}
		conv.f = static_cast<float>(conv.d);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		outputNonDisplayable(conv);
	}
}

void convertPseudo(const std::string &str, Conversions &conv)
{
	conv.NonDisplayable = true;
	conv.i = 0;
	
	if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
	{
		conv.f = std::stof(str);
		conv.d = static_cast<double>(conv.f);
	}
	else
	{
		conv.d = std::stod(str);
		conv.f = static_cast<float>(conv.d);
	}
}
