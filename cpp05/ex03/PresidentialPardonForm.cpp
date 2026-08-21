#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("unknown")
{
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{

}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " pardoned by Zaphod Beeblebrox" << std::endl;
}