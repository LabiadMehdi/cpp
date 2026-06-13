#include <iostream>
#include <ostream>
#include <cctype>
#include <string>

void	log(const char **message)
{
	int i = 0;
	while (message[i])
	{
		std::string word = message[i];
		for (int j = 0; j < (int)word.length(); j++)
			std::cout << (char)toupper(word[j]);
		if (message[i + 1])
			std::cout << ' ';
		i++;
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		log((const char **)argv + 1);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}