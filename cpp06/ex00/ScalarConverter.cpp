#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <cctype>
#include <limits>
#include <iomanip>

static bool	isChar(const std::string &literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[literal.length() - 1] == '\'');
}

static bool isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff");
}

static bool endWithF(const std::string &literal)
{
	size_t len = literal.length();
	if (len < 1)
		return false;
	return (literal[len - 1] == 'f');
}

static void	printChar(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char c = static_cast<char>(value);
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	return ;
}

static void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	int i = static_cast<int>(value);
	std::cout << "int: " << i << std::endl;
	return ;
}

static void printFloat(double value)
{
	if (std::isnan(value))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (std::signbit(value))
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: inff" << std::endl;
		return ;
	}
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	float f = static_cast<float>(value);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
}

static void printDouble(double value)
{
	if (std::isnan(value))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (std::signbit(value))
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: inf" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
}

static void	printAll(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

static double parsePseudoLiteral(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	else if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
		return std::numeric_limits<double>::infinity();
	else
		return -std::numeric_limits<double>::infinity();
}

static bool parseNumericLiteral(const std::string &literal, double &result)
{
	std::string numPart;
	if (endWithF(literal))
		numPart = literal.substr(0, literal.length() - 1);
	else
		numPart = literal;
	std::stringstream ss;
	ss << numPart;
	if (!(ss >> result) || !ss.eof())
		return false;
	return true;
}

void ScalarConverter::convert(const std::string &literal)
{
	double value;
	if (isChar(literal))
	{
		value = literal[1];
		printAll(value);
		return ;
	}
	if (isPseudoLiteral(literal))
	{
		value = parsePseudoLiteral(literal);
		printAll(value);
		return ;
	}
	if (parseNumericLiteral(literal, value))
	{
		printAll(value);
		return ;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}