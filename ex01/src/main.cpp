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
	int	option = 0;
	while (1)
	{
		displayMain();
		std::cin >> option;
		if (option == 3)
			break;
		else
			std::cout << "Invalid option" << std::endl;
	}
	return (0);
}
