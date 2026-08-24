#include "ScalarConverter.hpp"

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

void printAll(double value)
{
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

    std::cout << "double: " << value << std::endl;
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

static double parsePseudoLiteral(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	else if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff")
		return std::numeric_limits<double>::infinity();
	else
		return -std::numeric_limits<double>::infinity();
}

static void ScalarConvert::convert(const std::string &literal)
{

}