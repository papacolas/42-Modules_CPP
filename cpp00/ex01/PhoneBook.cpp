/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:44:25 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/06 12:38:11 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits.h>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	_index = 0;
	_count = 0;
}
PhoneBook::~PhoneBook()
{
	return;
}

std::string	PhoneBook::getInput(std::string prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			return "";
		}
		if (input.empty())
		{
			std::cout << "-------> This field can't be empty ! Try again please : <--------" << std::endl;
			continue;
		}

		if (prompt == "Enter the phone number: ")
		{
			size_t i = 0;
			bool isNumbers = true;

			while (i < input.length())
			{
				if (!std::isdigit(input[i]))
				{
					std::cout << "-------> The phone number must contain only numbers ! Try again please : <-------" << std::endl;
					// std::cin.clear();
					// input.clear();
					isNumbers = false;
					break;
				}
				i++;
			}
			if (!isNumbers)
				continue;
		}
		return input;
	}
}

void	PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;

	input = getInput("Enter first name: ");
	if (input.empty())
		return;
	newContact.setFirstName(input);

	input = getInput("Enter last name: ");
	if (input.empty())
		return;
	newContact.setLastName(input);

	input = getInput("Enter nick name: ");
	if (input.empty())
		return;
	newContact.setNickName(input);

	input = getInput("Enter the phone number: ");
	if (input.empty())
		return;
	newContact.setPhoneNumber(input);

	input = getInput("Enter the darkest secret of the contact: ");
	if (input.empty())
		return;
	newContact.setDarkestSecret(input);

	_phonebook[_index] = newContact;

	_index = (_index + 1) % 8;
	if (_count < 8)
		_count++;
}

std::string	PhoneBook::formatLength(std::string field)
{
	if (field.length() > 10)
	{
		return field.substr(0, 9) + ".";
	}
	return field;
}

void	PhoneBook::displayPhonebook()
{
	int	i = 0;

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	while (i < _count)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatLength(_phonebook[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatLength(_phonebook[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatLength(_phonebook[i].getNickName()) << std::endl;
		i++;
	}
}


void	PhoneBook::searchContact()
{
	std::string	input;
	int			index;

	if (_count == 0)
	{
		std::cout << "The phonebook is empty" << std::endl;
		return;
	}

	displayPhonebook();

	while (input.empty())
	{
		bool	isCorrect = true;

		std::cout << "enter an index: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input.empty())
			std::cout << "-------> This field can't be empty ! Try again please : <--------" << std::endl;
		std::stringstream ss(input);
		if (!(ss >> index) || !ss.eof())
		{
			std::cout << "-------> Invalid input ! Please enter a number : <-------" << std::endl;
			input.clear();
			isCorrect = false;
		}
		if (index < 0 || index >= _count)
		{
			if (isCorrect)
				std::cout << "-------> Invalid index ! Try an other please : <-------" << std::endl;
			input.clear();
		}
	}

	std::cout << "First name: " << _phonebook[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _phonebook[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _phonebook[index].getNickName() << std::endl;
	std::cout << "Phone number: " << _phonebook[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _phonebook[index].getDarkestSecret() << std::endl;
}


