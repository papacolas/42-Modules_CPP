/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:21:39 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/29 18:37:58 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) :
AForm("RobotomyRequestForm", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
AForm(other),
_target(other._target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}


void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() >= 45)
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::IsNotSignedException();

	std::cout << "**DRRRIIIIIIIIIIILLLLLLLLLLL**" << std::endl;

// Initialiser le générateur aléatoire une seule fois
	static bool initialized = false;
	if (!initialized) {
		std::srand(std::time(NULL));
		initialized = true;
	}

	// 50% de chance
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy of " << this->_target << " failed!" << std::endl;
}
