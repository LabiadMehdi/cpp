#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		void SetFirstName(std::string name);
		void SetLastName(std::string name);
		void SetNickName(std::string name);
		void SetPhoneNumber(std::string number);
		void SetDarkestSecret(std::string secret);
		std::string	GetFirstName();
		std::string	GetLastName();
		std::string	GetNickName();
		std::string	GetPhoneNumber();
		std::string	GetDarkestSecret();
};

#endif