#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
// #include <cctype>
#include "utils.hpp"

class Contact
{
	private:
		std::string id;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		//Getters
		std::string	getId();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
		//Setters
		void	setId(std::string id);
		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phoneNumber);
		void	setDarkestSecret(std::string darkestSecret);
};

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		int		contactCount;
		void	addContact();
		void	searchContact();
		void	displayContact(Contact contact);
};

void	displayMain();

#endif
