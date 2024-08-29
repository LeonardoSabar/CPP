#include "../include/PhoneBook.hpp"

void PhoneBook::addContact()
{
    Contact contact;
    std::string input, firstName, lastName, nickname, phoneNumber, darkestSecret;
    if (contactCount < 8)
    {
        std::cout << "Enter the first name: ";
        std::cin >> firstName;
        contact.setFirstName(firstName);
        std::cout << "Enter the last name: ";
        std::cin >> lastName;
        contact.setLastName(lastName);
        std::cout << "Enter the nickname: ";
        std::cin >> nickname;
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
    else
        std::cout << "The phone book is full" << std::endl;
}