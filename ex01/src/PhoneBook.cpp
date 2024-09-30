#include "../include/PhoneBook.hpp"


int notOnlySpaces(std::string input)
{
	int inputLen = input.length();
	int notOnlySpaces = 0;
	for (int i = 0; i < inputLen; i++)
	{
		if (notOnlySpaces == 1)
			break;
		if (!isspace(input[i]))
			notOnlySpaces = 1;
		else
		{
			std::cout << BRED << "Invalid input! The field cannot contain only spaces!" << RST << std::endl;
			return (1);
		}
	}
	return (0);
}

int validInput(std::string &input, int option)
{
	if (notOnlySpaces(input) == 1)
		return (1);
	if (option != 3 && (input.empty() || input.length() <= 1 || input.length() >= 30))
		{
			std::cout << BRED << "Invalid input! The name must be between 2 and 30 characters" << RST << std::endl;
			return (1);
		}
	if (option == 1)
	{
		int inputLen = input.length();
		for (int i = 0; i < inputLen - 1; i++)
		{
			if (!isalpha(input[i]) || isspace(input[i]))
			{
				std::cout << BRED << "Invalid input! The name must contain only letters an no spaces!" << RST << std::endl;
				return (1);
			}
		}
	}
	else if (option == 2)
	{
		if (input.empty() || input.size() < 2 || input.size() >= 30)
			return (1);
		std::string::const_iterator it;
		for (it = input.begin(); it != input.end(); it++)
		{
			if (!std::isalpha(*it) && !std::isspace(*it))
			{
				std::cout << std::endl << BRED << "Invalid input! The name must contain only letters and spaces!" << RST << std::endl;
				return (1);
			}
		}
	}
	else if (option == 3)
	{
		if (input.length() <= 1 || input.length() >= 15)
		{
			std::cout << std::endl << BRED << "Invalid input! The phone number must be between 1 and 15 characters!" << RST << std::endl;
			return (1);
		}
		int inputLen = input.length();
		for (int i = 0; i < inputLen; i++)
		{
			if (!isdigit(input[i]) && input[i] != '+' && input[i] != '(' && input[i] != ')' && input[i] != '-' && input[i] != ' ')
			{
				std::cout << std::endl << BRED << "Invalid input! The phone number must contain valid characters, please try again!" << RST << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

void PhoneBook::addContact()
{
	Contact contact;
	std::string input, firstName, lastName, nickname, phoneNumber, darkestSecret;
	if (_index > 7)
		_index = 0;
	int valueField = 1;

	while (valueField < 6)
	{
		int notValid = 1;
		while (valueField == 1)
		{
			std::cin.ignore(1000, '\n');
			while(notValid == 1)
			{
				std::cout << std::endl << BYEL << "Enter the first name: " << RST;
				std::getline(std::cin, firstName);
				if (validInput(firstName, 1) == 0)
				{
					notValid = 0;
					contact.setFirstName(firstName);
					valueField++;
				}
			}
		}
		while (valueField == 2)
		{
			notValid = 1;
			while(notValid == 1)
			{
				std::cout << BYEL << "Enter the last name: " << RST;
				std::getline(std::cin, lastName);
				if (validInput(lastName, 2) == 0)
				{
					notValid = 0;
					contact.setLastName(lastName);
					valueField++;
				}
			}
		}
		while (valueField == 3)
		{
			notValid = 1;
			while(notValid == 1)
			{
				std::cout << BYEL << "Enter the nickname: " << RST;
				std::getline(std::cin, nickname);
				if (validInput(nickname, 2) == 0)
				{
					notValid = 0;
					contact.setNickname(nickname);
					valueField++;
				}
			}
		}
		while (valueField == 4)
		{
			notValid = 1;
			while(notValid == 1)
			{
				std::cout << BYEL << "Enter the phone number: " << RST;
				std::getline(std::cin, phoneNumber);
				if (validInput(phoneNumber, 3) == 0)
				{
					notValid = 0;
					contact.setPhoneNumber(phoneNumber);
					valueField++;
				}
			}
		}
		while (valueField == 5)
		{
			notValid = 1;
			while(notValid == 1)
			{
				std::cout << BYEL << "Enter the darkest secret: " << RST;
				std::getline(std::cin, darkestSecret);
				if (validInput(darkestSecret, 2) == 0)
				{
					notValid = 0;
					contact.setDarkestSecret(darkestSecret);
					valueField++;
				}
			}
		}
	}
	contact.setId(_index);
	PhoneBook::contacts[_index] = contact;
	_index++;
	if (PhoneBook::contactCount < 8)
		PhoneBook::contactCount++;
	std::cout << BGRN << "Contact added successfully!" << RST << std::endl;
}

std::string truncate(std::string str, size_t width) {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	}
	return str;
}

void PhoneBook::displayContact(Contact c) {
	std::cout << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << c.getId() + 1	<< BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << truncate(c.getFirstName(), 10)	<< BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << truncate(c.getLastName(), 10)	<< BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << truncate(c.getNickname(), 10)
			  << BBLU << "|" << RST << std::endl;
}

void PhoneBook::searchContact()
{
	std::cout << BBLU << "+----------------------------------------------+" << RST << std::endl;
	std::cout << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << "Index"		<< BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << "First Name"	<< BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << "Last Name"	<< BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << "Nickname"
			  << BBLU << "|" << RST << std::endl;
	std::cout << BBLU << "+----------------------------------------------+" << RST << std::endl;

	while (PhoneBook::contactCount < 1)
	{
		std::cout << BRED << "No contacts available!" << RST << std::endl;
		return;
	}
	int index = 0;
	while (index < (contactCount))
		PhoneBook::displayContact(PhoneBook::contacts[index++]);

	index = 0;
	std::cout << BBLU << "+----------------------------------------------+" << RST << std::endl;
	std::cout << "Enter the index of the contact: " << std::endl;
	std::cin >> index;

	if (index < 1 || index > (contactCount))
	{
		std::cout << "Invalid input! The index must be a number beetween 1 and 8" << std::endl;
		return;
	}
	std::cout << BCYN << "Contact: " << RST << (index) << std::endl;
	std::cout << BCYN << "First Name: "		<< RST << contacts[index - 1].getFirstName()		<< std::endl;
	std::cout << BCYN << "Last Name: "		<< RST << contacts[index - 1].getLastName()		<< std::endl;
	std::cout << BCYN << "Nickname: "		<< RST << contacts[index - 1].getNickname()		<< std::endl;
	std::cout << BCYN << "Phone Number: "	<< RST << contacts[index - 1].getPhoneNumber()	<< std::endl;
	std::cout << BCYN << "Darkest Secret: "	<< RST << contacts[index - 1].getDarkestSecret()	<< std::endl;

}
