#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("unknown"), _signed(false), _tosign(75), _toexecute(75)
{}

Form::Form(std::string name, const int tosign, const int toexecute) : _name(name), _signed(false), _tosign(tosign), _toexecute(toexecute)
{
	if (_tosign < 1 || _toexecute < 1)
		throw Form::GradeTooHighException();
	if (_tosign > 150 || _toexecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _tosign(other._tosign), _toexecute(other._toexecute)
{
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

void	Form::beSigned(const Bureaucrat &employe)
{
	if (employe.getGrade() <= _tosign)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

const std::string Form::getName() const
{
	return _name;
}

bool	Form::getSigned() const
{
	return _signed;
}

int Form::getToSign() const
{
	return _tosign;
}

int Form::getToExecute() const
{
	return _toexecute;
}


std::ostream	&operator<<(std::ostream &out, const Form &other)
{
	out << "Form " << other.getName() << ", signed: " << other.getSigned() << ", grade to sign: " << other.getToSign() << ", grade to execute: " << other.getToExecute() << std::endl;
	return out;
}