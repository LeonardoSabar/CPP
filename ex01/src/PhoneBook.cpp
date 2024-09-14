#include "../include/PhoneBook.hpp"


int validInput(std::string input, int option)
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
				std::cout << "Invalid input! The name must contain only letters" << std::endl;
				return (1);
			}
		}
	}
	else if (option == 2)
	{
		if (input.length() <= 1 || input.length() >= 50)
		{
			std::cout << "Invalid input! The name must be between 1 and 30 characters" << std::endl;
			return (1);
		}
		int inputLen = input.length();
		for (int i = 0; i < inputLen; i++)
		{
			if (!isalpha(input[i]))
			{
				std::cout << "Invalid input! The name must contain only letters and spaces" << std::endl;
				return (1);
			}
		}
	}
	else if (option == 3)
	{
		if (input.length() <= 1 || input.length() >= 11)
		{
			std::cout << "Invalid input! The phone number must be between 1 and 10 characters" << std::endl;
			return (1);
		}
		int inputLen = input.length();
		for (int i = 0; i < inputLen; i++)
		{
			if (!isdigit(input[i]) || !isspace(input[i]) || input[i] != '+' || input[i] != '(' || input[i] != ')')
			{
				std::cout << "Invalid input! The phone number must contain valid characters" << std::endl;
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
	std::cout << "Enter the first name: ";
	std::cin >> firstName;
	if (validInput(firstName, 1))
		return;
	contact.setFirstName(firstName);
	std::cout << "Enter the last name: ";
	std::cin >> lastName;
	if (validInput(lastName, 2))
		return;
	contact.setLastName(lastName);
	std::cout << "Enter the nickname: ";
	std::cin >> nickname;
	if (validInput(nickname, 2))
		return;
	contact.setNickname(nickname);
	std::cout << "Enter the phone number: ";
	std::cin >> phoneNumber;
	contact.setPhoneNumber(phoneNumber);
	std::cout << "Enter the darkest secret: ";
	std::cin >> darkestSecret;
	contact.setDarkestSecret(darkestSecret);
	PhoneBook::contactCount++;
	std::stringstream ss;
	ss << PhoneBook::contactCount;
	std::string idStr = ss.str();
	contact.setId(idStr);
	PhoneBook::contacts[PhoneBook::contactCount] = contact;
}

std::string truncate(std::string str, size_t width) {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	}
	return str;
}


void PhoneBook::displayContact(Contact c) {
	std::cout << "|" << std::setw(10) << std::setfill(' ') << truncate(c.getId(), 10) << "|"
			  << "|" << std::setw(10) << std::setfill(' ') << truncate(c.getFirstName(), 10) << "|"
			  << "|" << std::setw(10) << std::setfill(' ') << truncate(c.getLastName(), 10) << "|"
			  << "|" << std::setw(10) << std::setfill(' ') << truncate(c.getNickname(), 10)
			  << "|" << std::endl;
}

void PhoneBook::searchContact()
{
	std::cout << "|" << std::setw(10) << std::setfill(' ') << "Index" << "|"
			  << "|" << std::setw(10) << std::setfill(' ') << "First Name" << "|"
			  << "|" << std::setw(10) << std::setfill(' ') << "Last Name" << "|"
			  << "|" << std::setw(10) << std::setfill(' ') << "Nickname"
			  << "|" << std::endl;

	for (int i = 1; i <= contactCount; i++)
	{
		PhoneBook::displayContact(PhoneBook::contacts[i]);
	}
	std::string index;
	std::cout << "Enter the index of the contact: ";
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
		std::cout << "Invalid index" << std::endl;
		return;
	}
	Contact c = contacts[indexInt];
	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;

}
