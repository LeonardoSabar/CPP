#include "../include/PhoneBook.hpp"
#include <iostream>


void	displayMain()
{
	std::cout << "Choose one of the numbers below: " << std::endl;
	std::cout << "1 - ADD" << std::endl;
	std::cout << "2 - SEARCH" << std::endl;
	std::cout << "3 - EXIT" << std::endl;
}


int	main()
{
	PhoneBook	phoneBook;
	phoneBook.contactCount = 0;
	std::string option;
	while (1)
	{
		displayMain();
		std::cout << "Enter your option" << BLNK << ": " << RST;
		std::cin >> option;
			if (option.compare("1") == 0 || option.compare("ADD") == 0)
				phoneBook.addContact();
			else if (option.compare("2") == 0 || option.compare("SEARCH") == 0)
				phoneBook.searchContact();
			else if (option.compare("3") == 0 || option.compare("EXIT") == 0)
				break;
			else
				std::cout << "Invalid option" << std::endl;
	}
	return (0);
}
