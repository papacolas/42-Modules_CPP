/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:58:31 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/10 16:54:06 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const &str)
{
	this->_type = str;
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(void) const
{
	return this->_type;
}

void Weapon::setType(std::string const &type)
{
	this->_type = type;
}
