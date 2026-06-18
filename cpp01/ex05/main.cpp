#include "Harl.hpp"

int main(void)
{
	Harl log;
	log.complain("DEBUG");
	log.complain("INFO");
	log.complain("WARNING");
	log.complain("ERROR");
	log.complain("BANANA");
	return (0);
}