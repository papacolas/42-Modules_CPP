/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:19:53 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/04 16:11:10 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
	(void)other;
	return ;
}

Intern::~Intern()
{}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}


AForm	*Intern::createRobotomyForm(std::string targetForm)
{
	return new RobotomyRequestForm(targetForm);
}

AForm	*Intern::createShrubberyForm(std::string targetForm)
{
	return new ShrubberyCreationForm(targetForm);
}

AForm	*Intern::createPresidentialPardonForm(std::string targetForm)
{
	return new PresidentialPardonForm(targetForm);
}


AForm* Intern::makeForm(std::string nameForm, std::string targetForm)
{
	std::string	formsNames[] = {"robotomy request",
								"shrubbery creation",
								"presidential pardon"};

	AForm	*(Intern::*choiceForm[])(std::string targetForm) = {
										&Intern::createRobotomyForm,
										&Intern::createShrubberyForm,
										&Intern::createPresidentialPardonForm};


	for (int i = 0; i < 3; i++)
	{
		if (nameForm == formsNames[i])
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return ((this->*choiceForm[i])(targetForm));
		}
	}
		std::cout << "Error : the form request doesn't exist" << std::endl;
	return NULL;
}







// void Harl::complain(std::string level)
// {
// 	std::string	comments[] = {
// 						"DEBUG",
// 						"INFO",
// 						"WARNING",
// 						"ERROR"};
// 	void		(Harl::*levels[])() = {
// 						&Harl::debug,
// 						&Harl::info,
// 						&Harl::warning,
// 						&Harl::error};
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (level == comments[i])
// 			(this->*levels[i])();
// 	}
// }
