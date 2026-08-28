#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <exception>

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::exception();

	std::string	line;
	std::getline(file, line);

	while(std::getline(file, line))
	{
		size_t	commapos = line.find(',');
		std::string date = line.substr(0, commapos);
		std::string rate = line.substr(commapos + 1);
		std::stringstream ss;
		ss << rate;
		float ratef;
		ss >> ratef;
		_hmap.insert(std::pair<std::string, float>(date, ratef));
	}
}

float BitcoinExchange::bitcoinRate(std::string date) const
{
	std::map<std::string, float>::const_iterator it = _hmap.lower_bound(date);

	if (it != _hmap.end() && it->first == date)
		return it->second;

	if (it == _hmap.begin())
		throw std::exception();
	
	--it;
	return it->second;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _hmap(other._hmap)
{
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return *this;
	_hmap = other._hmap;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}