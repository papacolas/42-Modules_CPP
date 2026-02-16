/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:21:04 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/29 17:24:15 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm(void) :
_name("Inconnu"),
_isSigned(false),
_grade_sign_it(80),
_grade_exectute_it(50)
{}

AForm::AForm(std::string name, int signIt, int executeIt) :
_name(name),
_isSigned(false),
_grade_sign_it(signIt),
_grade_exectute_it(executeIt)
{
	if (_grade_sign_it > 150 || _grade_exectute_it > 150)
		throw AForm::GradeTooLowException();
	else if (_grade_sign_it < 1 || _grade_exectute_it < 1)
		throw AForm::GradeTooHighException();
	return;
}

AForm::AForm(const AForm &other) :
_name(other._name),
_isSigned(false),
_grade_sign_it(other._grade_sign_it),
_grade_exectute_it(other._grade_exectute_it)
{}

AForm::~AForm(void)
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int	AForm::getGradeSignIt() const
{
	return (this->_grade_sign_it);
}

int	AForm::getGradeExecuteIt() const
{
	return (this->_grade_exectute_it);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("**** Invalid Grade : Too high ****");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("**** Invalid Grade : Too low ****");
}

const char *AForm::IsNotSignedException::what() const throw()
{
	return ("**** Form has not been signed ****");
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName()
		<< ", AForm is signed ? : " << AForm.getIsSigned()
		<< ", grade to sign it : " << AForm.getGradeSignIt()
		<< ", grade to execute it : " << AForm.getGradeExecuteIt()
		<< std::endl;

	return out;
}


void	AForm::beSigned(const Bureaucrat &bcrat)
{
	// if (this->_isSigned == true)
	// 	return;
	if (bcrat.getGrade() > this->_grade_sign_it)
	{
		throw AForm::GradeTooLowException();
	}
	this->_isSigned = true;
}
