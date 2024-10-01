/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:05:52 by leobarbo          #+#    #+#             */
/*   Updated: 2024/09/30 20:05:52 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int notOnlySpaces(std::string input)
{
	int i = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')
			return (0);
	}
	return (1);
}


int validInput(std::string &input, int option)
{
    if (notOnlySpaces(input) == 1)
        return (1);

    switch (option)
    {
        case 1:
            if (input.empty() || input.length() <= 1 || input.length() >= 30)
            {
                std::cout << BRED << "Invalid input! The name must be between 2 and 30 characters" << RST << std::endl;
                return (1);
            }
            for (char c : input)
            {
                if (!isalpha(c) || isspace(c))
                {
                    std::cout << BRED << "Invalid input! The name must contain only letters and no spaces!" << RST << std::endl;
                    return (1);
                }
            }
            break;

        case 2:
            if (input.empty() || input.length() < 2 || input.length() >= 30)
            {
                std::cout << BRED << "Invalid input! The input must be between 2 and 30 characters" << RST << std::endl;
                return (1);
            }
            for (char c : input)
            {
                if (!std::isalpha(c) && !std::isspace(c))
                {
                    std::cout << BRED << "Invalid input! The input must contain only letters and spaces!" << RST << std::endl;
                    return (1);
                }
            }
            break;

        case 3:
            if (input.length() <= 2 || input.length() >= 15)
            {
                std::cout << BRED << "Invalid input! The phone number must be between 2 and 15 characters!" << RST << std::endl;
                return (1);
            }
            for (char c : input)
            {
                if (!isdigit(c) && c != '+' && c != '(' && c != ')' && c != '-' && c != ' ')
                {
                    std::cout << BRED << "Invalid input! The phone number must contain valid characters!" << RST << std::endl;
                    return (1);
                }
            }
            break;

        default:
            std::cout << BRED << "Invalid option!" << RST << std::endl;
            return (1);
    }

    return (0);
}


void PhoneBook::addContact()
{
    Contact contact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    if (_index > 7)
        _index = 0;
    
    int valueField = 1;
    int notValid;

    while (valueField <= 5)
    {
        notValid = 1;
        switch (valueField)
        {
            case 1:
                std::cin.ignore(1000, '\n');
                while (notValid)
                {
                    std::cout << std::endl << BYEL << "Enter the first name: " << RST;
                    std::getline(std::cin, firstName);
                    if (validInput(firstName, 1) == 0)
                    {
                        contact.setFirstName(firstName);
                        notValid = 0;
                    }
                }
                valueField++;
                break;

            case 2:
                while (notValid)
                {
                    std::cout << BYEL << "Enter the last name: " << RST;
                    std::getline(std::cin, lastName);
                    if (validInput(lastName, 2) == 0)
                    {
                        contact.setLastName(lastName);
                        notValid = 0;
                    }
                }
                valueField++;
                break;

            case 3:
                while (notValid)
                {
                    std::cout << BYEL << "Enter the nickname: " << RST;
                    std::getline(std::cin, nickname);
                    if (validInput(nickname, 2) == 0)
                    {
                        contact.setNickname(nickname);
                        notValid = 0;
                    }
                }
                valueField++;
                break;

            case 4:
                while (notValid)
                {
                    std::cout << BYEL << "Enter the phone number: " << RST;
                    std::getline(std::cin, phoneNumber);
                    if (validInput(phoneNumber, 3) == 0)
                    {
                        contact.setPhoneNumber(phoneNumber);
                        notValid = 0;
                    }
                }
                valueField++;
                break;

            case 5:
                while (notValid)
                {
                    std::cout << BYEL << "Enter the darkest secret: " << RST;
                    std::getline(std::cin, darkestSecret);
                    if (validInput(darkestSecret, 2) == 0)
                    {
                        contact.setDarkestSecret(darkestSecret);
                        notValid = 0;
                    }
                }
                valueField++;
                break;
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
		std::cout << BRED << "Invalid index!" << RST << std::endl;
		return;
	}
	std::cout << BCYN << "Contact: " << RST << (index) << std::endl;
	std::cout << BCYN << "First Name: "		<< RST << contacts[index - 1].getFirstName()		<< std::endl;
	std::cout << BCYN << "Last Name: "		<< RST << contacts[index - 1].getLastName()			<< std::endl;
	std::cout << BCYN << "Nickname: "		<< RST << contacts[index - 1].getNickname()			<< std::endl;
	std::cout << BCYN << "Phone Number: "	<< RST << contacts[index - 1].getPhoneNumber()		<< std::endl;
	std::cout << BCYN << "Darkest Secret: "	<< RST << contacts[index - 1].getDarkestSecret()	<< std::endl;
}
