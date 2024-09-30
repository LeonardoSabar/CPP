#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include "utils.hpp"

class Contact
{
	private:
		int			id;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:

		Contact(void);
		~Contact(void);

		//Setters and Getters
		int	getId();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();

		void	setId(int id);
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

		PhoneBook(void);
		~PhoneBook(void);

		int		contactCount;
		int		_index;
		void	addContact();
		void	searchContact();
		void	displayContact(Contact contact);
};

void	displayMain();

#endif
