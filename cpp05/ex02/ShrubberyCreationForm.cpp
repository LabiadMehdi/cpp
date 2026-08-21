#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("unknown")
{
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{

}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "   *   \n  ***  \n ***** \n   |   \n";
	file.close();
}