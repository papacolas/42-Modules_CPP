/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:53:22 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/29 15:39:08 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(void) :
_name("Inconnu"),
_isSigned(false),
_grade_sign_it(80),
_grade_exectute_it(50)
{}

Form::Form(std::string name, int signIt, int executeIt) :
_name(name),
_isSigned(false),
_grade_sign_it(signIt),
_grade_exectute_it(executeIt)
{
	if (_grade_sign_it > 150 || _grade_exectute_it > 150)
		throw Form::GradeTooLowException();
	else if (_grade_sign_it < 1 || _grade_exectute_it < 1)
		throw Form::GradeTooHighException();
	return;
}

Form::Form(const Form &other) :
_name(other._name),
_isSigned(false),
_grade_sign_it(other._grade_sign_it),
_grade_exectute_it(other._grade_exectute_it)
{}

Form::~Form(void)
{}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int	Form::getGradeSignIt() const
{
	return (this->_grade_sign_it);
}

int	Form::getGradeExecuteIt() const
{
	return (this->_grade_exectute_it);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("**** Invalid Grade : Too high ****");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("**** Invalid Grade : Too low ****");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName()
		<< ", Form is signed ? : " << form.getIsSigned()
		<< ", grade to sign it : " << form.getGradeSignIt()
		<< ", grade to execute it : " << form.getGradeExecuteIt()
		<< std::endl;

	return out;
}


void	Form::beSigned(const Bureaucrat &bcrat)
{
	// if (this->_isSigned == true)
	// 	return;
	if (bcrat.getGrade() > this->_grade_sign_it)
	{
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
}
