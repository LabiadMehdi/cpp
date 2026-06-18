#include "Error.hpp"

int	Error(int argc, char **argv, std::ifstream &file, std::ofstream &outFile)
{
	if (argc != 4)
	{
		std::cout << "Number of parameters must be three." << std::endl;
		return (1);
	}
	if (!argv[2][0])
	{
		std::cout << "Cannot accept an empty string to be replaced." << std::endl;
		return (1);
	}
	file.open(argv[1]);
	if (!file)
	{
		std::cout << "Cannot open: "<< argv[1] << std::endl;
		return (1);
	}
	outFile.open((std::string(argv[1]) + ".replace").c_str());
	if (!outFile)
	{
		file.close();
		std::cout << "Cannot create: "<< std::string(argv[1]) + ".replace" << std::endl;
		return (1);
	}
	return (0);
}