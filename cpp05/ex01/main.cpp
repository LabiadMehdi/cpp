#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat employe1("Elliot", 3);
	Bureaucrat employe2("Néo", 45);

	Form form1("formulaire 1", 10, 10);
	
	employe1.signForm(form1);
	employe2.signForm(form1);
}