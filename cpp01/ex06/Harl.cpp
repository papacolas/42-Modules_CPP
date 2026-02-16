/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:03:40 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/12 16:36:37 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string	comments[] = {
						"DEBUG",
						"INFO",
						"WARNING",
						"ERROR"};
	void		(Harl::*levels[])() = {
						&Harl::debug,
						&Harl::info,
						&Harl::warning,
						&Harl::error};
	int i = 0;
	while (i < 4)
	{
		if (level == comments[i])
		{
			(this->*levels[i])();
			break;
		}
		i++;
	}

	switch (i)
	{
		case 0:
			for (int j = 1; j < 4; j++)
			{
				std::cout << std::endl;
				(this->*levels[j])();
			}
			std::cout << std::endl;
			break;
		case 1:
			for (int j = 2; j < 4; j++)
			{
				std::cout << std::endl;
				(this->*levels[j])();
			}
			std::cout << std::endl;
			break;
		case 2:
			for (int j = 3; j < 4; j++)
			{
				std::cout << std::endl;
				(this->*levels[j])();
			}
			std::cout << std::endl;
			break;
		default:
			std::cout << std::endl;
			std::cout << "There is no more level ! Goodbye !" << std::endl;

	}
}
