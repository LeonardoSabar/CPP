/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:08:15 by leobarbo          #+#    #+#             */
/*   Updated: 2024/09/30 20:08:15 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/megaphone.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::string	line;
		unsigned long words;
		for (words = 1; argv[words] != '\0'; words++)
		{
			line = argv[words];
			transform(line.begin(), line.end(), line.begin(), ::toupper);
			std::cout << line;
		}
		std::cout << std::endl;
		}
		else
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
