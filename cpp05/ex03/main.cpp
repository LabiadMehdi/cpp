#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include "Intern.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat employe1("Elliot", 3);
	
	Intern intern1;
	
	AForm *formObama = intern1.makeForm("presidential pardon", "Obama");

	employe1.signForm(*formObama);
	employe1.executeForm(*formObama);

	delete formObama;
}