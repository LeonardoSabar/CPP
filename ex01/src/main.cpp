#include "../include/PhoneBook.hpp"


void	displayMain()
{
	std::cout << BBLU << "+----------------------------------------------+" << RST << std::endl;
	std::cout << std::setw(22) << UNDL << "PHONEBOOK" << RST << std::endl;
	std::cout << BBLU << "+----------------------------------------------+" << RST << std::endl;
	std::cout << "Choose one of the following options:" << std::endl;
	std::cout << BRED << "1 " << RST << BOLD << "- ADD"		<< RST		<< std::endl;
	std::cout << BRED << "2 " << RST << BOLD << "- SEARCH"	<< RST		<< std::endl;
	std::cout << BRED << "3 " << RST << BOLD << "- EXIT"	<< RST		<< std::endl;
}


int	main()
{
	PhoneBook	phoneBook;
	phoneBook.contactCount = 0;
	std::string option;
	while (1)
	{
		displayMain();
		std::cout << std::endl << BRED << "Enter your option" << BLNK << ": " << RST;
		std::cin >> option;
			if (option.compare("1") == 0 || option.compare("ADD") == 0)
				phoneBook.addContact();
			else if (option.compare("2") == 0 || option.compare("SEARCH") == 0)
				phoneBook.searchContact();
			else if (option.compare("3") == 0 || option.compare("EXIT") == 0)
				break;
			else
				std::cout << BRED << "Invalid option. Please try again!" << RST << std::endl << std::endl;
	}
	return (0);
}
