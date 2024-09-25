#include "../include/PhoneBook.hpp"


int validInput(std::string &input, int option)
{
	if (option == 1)
	{
		if (input.length() <= 1 || input.length() >= 30)
		{
			std::cout << "Invalid input! The name must be between 1 and 30 characters" << std::endl;
			return (1);
		}
		int inputLen = input.length();
		for (int i = 0; i < inputLen - 1; i++)
		{
			if (!isalpha(input[i]) || isspace(input[i]))
			{
				std::cout << "Invalid input! The name must contain only letters!" << std::endl;
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
				std::cout << std::endl << RED << "Invalid input! The name must contain only letters and spaces" << RST << std::endl;
				return (1);
			}
		} 
	}
	else if (option == 3)
	{
		if (input.length() <= 1 || input.length() >= 11)
		{
			std::cout << std::endl << RED << "Invalid input! The phone number must be between 1 and 10 characters" << RST << std::endl;
			return (1);
		}
		int inputLen = input.length();
		for (int i = 0; i < inputLen; i++)
		{
			if (!isdigit(input[i]) && input[i] != '+' && input[i] != '(' && input[i] != ')')
			{
				std::cout << std::endl << RED << "Invalid input! The phone number must contain valid characters, please try again!" << RST << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

void PhoneBook::addContact()
{
	Contact contact;
	std::string id, input, firstName, lastName, nickname, phoneNumber, darkestSecret;
	if (PhoneBook::contactCount >= 8)
		PhoneBook::contactCount = 1;

	int valueField = 1;
	while (valueField < 6)
	{
		int notValid = 1;
		while (valueField == 1)
		{
			std::cin.ignore(1000, '\n');
			while(notValid == 1)
			{
				std::cout << "Enter the first name: ";
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
				std::cout << "Enter the last name: ";
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
				std::cout << "Enter the nickname: ";
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
				std::cout << "Enter the phone number: ";
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
				std::cout << "Enter the darkest secret: ";
				std::getline(std::cin, darkestSecret);
				if (validInput(darkestSecret, 2) == 0)
				{
					notValid = 0;
					contact.setDarkestSecret(darkestSecret);
					valueField++;
				}
			}
		}
	
	std::stringstream ss;
	ss << PhoneBook::contactCount;
	std::string idStr = ss.str();
	contact.setId(idStr);
	PhoneBook::contacts[PhoneBook::contactCount] = contact;
	PhoneBook::contactCount++;
	}
}

std::string truncate(std::string str, size_t width) {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	}
	return str;
}

void PhoneBook::displayContact(Contact c) {
	std::cout << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << truncate(c.getId(), 10) << BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << truncate(c.getFirstName(), 10) << BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << truncate(c.getLastName(), 10) << BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << truncate(c.getNickname(), 10)
			  << BBLU << "|" << RST << std::endl;
}

void PhoneBook::searchContact()
{
	std::cout << BBLU << "+----------------------------------------------+" << RST << std::endl;
	std::cout << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << "Index" << BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << "First Name" << BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << "Last Name" << BBLU << "|" << RST
			  << BBLU << "|" << RST << std::setw(10) << std::setfill(' ') << "Nickname"
			  << BBLU << "|" << RST << std::endl;
	std::cout << BBLU << "+----------------------------------------------+" << RST << std::endl;

	for (int i = 1; i <= contactCount - 1; i++)
	{
		PhoneBook::displayContact(PhoneBook::contacts[i]);
	}
	std::string index;
	std::cout << BBLU << "+----------------------------------------------+" << RST << std::endl;
	std::cout << "Enter the index of the contact: " << std::endl;
	std::cin >> index;

	if (index.length() != 1 || !isdigit(index[0]))
	{
		std::cout << "Invalid input! The index must be a number beetween 1 and 8" << std::endl;
		return;
	}
	std::stringstream ss(index);
	int indexInt;
	ss >> indexInt;
	std::cout << "Index: " << indexInt << std::endl;
	if (indexInt < 0 || indexInt > contactCount)
	{
		std::cout << BRED << "Invalid index!" << RST << std::endl << std::endl;
		return;
	}
	Contact c = contacts[indexInt];
	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;

}
