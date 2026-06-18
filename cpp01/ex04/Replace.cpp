#include "Replace.hpp"

void	replace(std::ifstream &file, std::ofstream &outFile, std::string s1, std::string s2)
{
	std::string line;
	size_t		pos;
	size_t		start;
	while (std::getline(file, line))
	{
		start = 0;
		while ((pos = line.find(s1, start)) != std::string::npos)
		{
			outFile << line.substr(start, pos - start) << s2;
			start = pos + s1.length();
		}
		outFile << line.substr(start) << std::endl;
	}
}