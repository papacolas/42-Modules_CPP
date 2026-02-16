/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:21:31 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/29 18:36:02 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("PresidentialPardonForm", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5),
_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
AForm(other),
_target(other._target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}


void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() >= 5)
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::IsNotSignedException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;

}
