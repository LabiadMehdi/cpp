#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main(void)
{
	srand(time(NULL));

	Bureaucrat employe1("Elliot", 3);
	Bureaucrat employe2("Néo", 150);
	Bureaucrat employe3("Marcel", 30);

	ShrubberyCreationForm form1("garden");
	
	employe1.signForm(form1);
	employe1.executeForm(form1);

	employe2.executeForm(form1);

	RobotomyRequestForm form2("Blopers");

	employe3.signForm(form2);
	employe3.executeForm(form2);

	PresidentialPardonForm form3("Press");

	employe1.executeForm(form3);
	employe1.signForm(form3);
	employe1.executeForm(form3);
}