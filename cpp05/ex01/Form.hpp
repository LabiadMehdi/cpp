#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _tosign;
		const int _toexecute;
	public:
		Form();
		Form(std::string name, const int _tosign, const int _toexecute);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void beSigned(const Bureaucrat &other);

		const std::string getName() const;
		bool	getSigned() const;
		int getToSign() const;
		int getToExecute() const;
};

std::ostream	&operator<<(std::ostream &out, const Form &other);

#endif