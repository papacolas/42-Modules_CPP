/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:58:22 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/10 17:11:48 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string const &name) : _name(name), _weapon(NULL)
{
	// this->_name = name;
	// this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (_weapon == NULL)
	{
		std::cout << _name << " has no weapon !!" << std::endl;
		return;
	}
	std::cout << _name  << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	_weapon = &w;
}
