#include "BitcoinExchange.hpp"
#include <cctype>
#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>

enum ValueError {VALID, PARSE_ERROR, NEGATIVE, TOO_LARGE};

bool isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	std::stringstream ssmonth;
	std::stringstream ssday;

	ssmonth << date.substr(5, 2);
	ssday << date.substr(8, 2);

	int month;
	int day;

	ssmonth >> month;
	ssday >> day;
	
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	return true;
}

ValueError checkValue(const std::string &value, float &parsedvalue)
{
	double dvalue;
	std::stringstream valueToDouble;
	valueToDouble << value;

	if (!(valueToDouble >> dvalue) || !valueToDouble.eof())
		return PARSE_ERROR;

	if (dvalue < 0)
		return NEGATIVE;

	if (dvalue > 1000)
		return TOO_LARGE;

	parsedvalue = static_cast<float>(dvalue);
	return VALID;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc("data.csv");
		std::ifstream userFile(av[1]);
		if (!userFile.is_open())
		{
			std::cerr << "Error: could not open file." << std::endl;
			return 1;
		}
		
		std::string	line;
		std::getline(userFile, line);
		while(std::getline(userFile, line))
		{
			std::string date = line.substr(0, 10);
			if (!isValidDate(date))
			{
				std::cerr << "Error: bad input => "<< date << std::endl;
				continue;
			}
			float val;
			ValueError err = checkValue(line.substr(line.find('|') + 2), val);
			if (err == NEGATIVE)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (err == TOO_LARGE)
				std::cerr << "Error: too large a number." << std::endl;
			else if (err == PARSE_ERROR)
				std::cerr << "Error: bad input => " << line << std::endl;
			else
			{
				try
				{
					float rate = btc.bitcoinRate(date);
					float res = val * rate;
					std::cout << date << " => " << val << " = " << res << std::endl;
				}
				catch(const std::exception& e)
				{
					std::cerr << "Error: bad input => "<< date << std::endl;
				}
			}
		}
	}
	catch (...)
	{
		std::cerr << "Error: could not open data.csv file." << std::endl;
		return 1;
	}

	return (0);
}