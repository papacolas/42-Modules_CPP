/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:52:12 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/06 10:16:08 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"


Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::getFirstName(void) const
{
	return this->_firstname;
}

void	Contact::setFirstName(std::string first)
{
	this->_firstname = first;
}

std::string	Contact::getLastName(void) const
{
	return this->_lastname;
}

void	Contact::setLastName(std::string last)
{
	this->_lastname = last;
}

std::string	Contact::getNickName(void) const
{
	return this->_nickname;
}

void	Contact::setNickName(std::string nick)
{
	this->_nickname = nick;
}

std::string	Contact::getPhoneNumber(void) const
{
	return this->_phonenumber;
}

void	Contact::setPhoneNumber(std::string phone)
{
	this->_phonenumber = phone;
}

std::string	Contact::getDarkestSecret(void) const
{
	return this->_darkest_secret;
}

void	Contact::setDarkestSecret(std::string secret)
{
	this->_darkest_secret = secret;
}
