#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "utils.hpp"
#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		//Getters
		std::string getFirstName()
		{
			return (firstName);
		}
		std::string getLastName()
		{
			return (lastName);
		}
		std::string getNickname()
		{
			return (nickName);
		}
		std::string getPhoneNumber()
		{
			return (phoneNumber);
		}
		std::string getDarkSecret()
		{
			return (darkestSecret);
		}

		//Setters
		void setFirstName(std::string firstName)
		{
			this->firstName = firstName;
		}
		void setLastName(std::string lastName)
		{
			this->lastName = lastName;
		}
		void setNickname(std::string nickName)
		{
			this->nickName = nickName;
		}
		void setPhoneNumber(std::string phoneNumber)
		{
			this->phoneNumber = phoneNumber;
		}
		void setDarkestSecret(std:: string darkestSecret)
		{
			this->darkestSecret = darkestSecret;
		}

};

class PhoneBook
{
	Contact contacts[8];
	unsigned int idx;


}
#endif
