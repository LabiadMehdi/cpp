#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm *createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm *createPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string formname, std::string target) const
{
	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[])(std::string) = {
		&createShrubbery,
		&createRobotomy,
		&createPardon
	};

	AForm *form;
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formname)
		{
			form = creators[i](target);
			std::cout << "Intern creates " << formname << std::endl;
			return form;
		}
	}
	std::cout << "Intern: form '" << formname << "' doesn't exist." << std::endl;
	return NULL;
}