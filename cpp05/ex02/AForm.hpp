#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _tosign;
		const int _toexecute;
	public:
		AForm();
		AForm(std::string name, const int _tosign, const int _toexecute);
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		~AForm();

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		void beSigned(const Bureaucrat &other);

		const std::string getName() const;
		bool	getSigned() const;
		int getToSign() const;
		int getToExecute() const;

		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &out, const AForm &other);

#endif