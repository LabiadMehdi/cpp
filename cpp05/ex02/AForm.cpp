#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("unknown"), _signed(false), _tosign(75), _toexecute(75)
{}

AForm::AForm(std::string name, const int tosign, const int toexecute) : _name(name), _signed(false), _tosign(tosign), _toexecute(toexecute)
{
	if (_tosign < 1 || _toexecute < 1)
		throw AForm::GradeTooHighException();
	if (_tosign > 150 || _toexecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _tosign(other._tosign), _toexecute(other._toexecute)
{
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm()
{}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed.";
}

void	AForm::beSigned(const Bureaucrat &employe)
{
	if (employe.getGrade() <= _tosign)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

const std::string AForm::getName() const
{
	return _name;
}

bool	AForm::getSigned() const
{
	return _signed;
}

int AForm::getToSign() const
{
	return _tosign;
}

int AForm::getToExecute() const
{
	return _toexecute;
}


std::ostream	&operator<<(std::ostream &out, const AForm &other)
{
	out << "AForm " << other.getName() << ", signed: " << other.getSigned() << ", grade to sign: " << other.getToSign() << ", grade to execute: " << other.getToExecute() << std::endl;
	return out;
}