#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
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
		//Setters and Getters
		std::string	getId();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();

		void	setId(std::string id);
		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phoneNumber);
		void	setDarkestSecret(std::string darkestSecret);

		// void	displayContact();
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
