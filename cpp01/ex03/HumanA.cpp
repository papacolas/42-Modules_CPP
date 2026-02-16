/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:58:16 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/10 17:13:47 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string const &name, Weapon &w) : _name(name), _weapon(w)
{
}

HumanA::~HumanA()
{
}
void	HumanA::attack()
{
	std::cout << _name  << " attacks with their " << _weapon.getType() << std::endl;
}
