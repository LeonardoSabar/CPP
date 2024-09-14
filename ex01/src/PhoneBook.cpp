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
            for (int i = 0; i < input.length(); i++)
            {
                if (!isalpha(input[i]) || !isspace(input[i]))
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
        for (int i = 0; i < input.length(); i++)
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
        for (int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]) || !isspace(input[i]) || !input[i] == '+' || !input[i] == '(' || !input[i] == ')')
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
    std::string input, firstName, lastName, nickname, phoneNumber, darkestSecret;
    if (contactCount >= 8)
        contactCount = 0;
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
    contacts[contactCount] = contact;
    contactCount++;
}