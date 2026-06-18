#include "Error.hpp"
#include "Replace.hpp"

int main(int argc, char **argv)
{
	std::ifstream	file;
	std::ofstream	outFile;
	if (Error(argc, argv, file, outFile))
		return (1);
	replace(file, outFile, argv[2], argv[3]);
	file.close();
	outFile.close();
	return (0);
}