#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
}


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{

}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "DRRRRR DRRRRR\n";
	if (rand() % 2 == 0)
		std::cout << _target << " has been succesfuly robotomyzed" << std::endl;
	else
		std::cout << "The robotomization failed." << std::endl;
}