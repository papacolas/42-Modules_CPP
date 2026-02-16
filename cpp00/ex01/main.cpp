/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:52:15 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/06 11:41:39 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iostream>
#include <limits.h>
#include <cstdlib>

int	main(void)
{
	PhoneBook	phoneB;
	std::string	command;

	while (true)
	{
		std::cout << "Enter a command (ADD or SEARCH or EXIT): ";

		if (!std::getline(std::cin, command))
		{
			break;
		}
		else if (command == "EXIT")
		{
			break;
		}
		else if (command == "ADD")
		{
			phoneB.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneB.searchContact();
		}
		else
		{
			std::cout << "Invalid command, try again !" << std::endl;
		}
		command.clear();
	}

	return 0;
}
