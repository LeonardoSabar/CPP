/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:06:15 by leobarbo          #+#    #+#             */
/*   Updated: 2024/09/30 20:06:15 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

void	displayMain()
{
	std::cout << BBLU << "+----------------------------------------------+"	<< RST << std::endl;
	std::cout << std::setw(22) << UNDL << BBLU << "PHONEBOOK"				<< RST << std::endl;
	std::cout << BBLU << "+----------------------------------------------+"	<< RST << std::endl;
	std::cout << BWHT <<"Choose one of the following options:"	<< RST		<< std::endl;
	std::cout << BRED << "1 " << RST << BOLD << "- ADD"			<< RST		<< std::endl;
	std::cout << BRED << "2 " << RST << BOLD << "- SEARCH"		<< RST		<< std::endl;
	std::cout << BRED << "3 " << RST << BOLD << "- EXIT"		<< RST		<< std::endl;
	std::cout << BYEL << "Enter your option" << BLNK << ": "	<< RST;
}


int	main()
{
	PhoneBook	phoneBook;
	std::string option;
	while (1)
	{
		displayMain();
		std::clearerr(stdin);
		std::cin.clear();
		std::cin >> option;
			if (option.compare("1") == 0 || option.compare("ADD") == 0)
				phoneBook.addContact();
			else if (option.compare("2") == 0 || option.compare("SEARCH") == 0)
				phoneBook.searchContact();
			else if (option.compare("3") == 0 || option.compare("EXIT") == 0)
				break;
			else
				std::cout << std::endl << BRED << "Invalid option. Please try again!" << RST << std::endl << std::endl;
	}
	return (0);
}
