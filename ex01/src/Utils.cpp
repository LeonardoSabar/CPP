/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:32:11 by leobarbo          #+#    #+#             */
/*   Updated: 2024/09/30 21:32:11 by leobarbo         ###   ########.fr       */
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
