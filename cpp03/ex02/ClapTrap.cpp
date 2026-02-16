/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:08:30 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/20 13:10:20 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_name("no_name"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0),
	_className("ClapTrap")
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0),
	_className("ClapTrap")
{
	std::cout << "ClapTrap Constructor called for : " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage),
	_className(other._className)
{
	std::cout << "ClapTrap Copy constructor called for : " << other._name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for : " << this->_name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment called for : " << this->_name << " = " << other._name << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->_className = other._className;
	}
	return *this;
}

// -----Fonctions membres-----//

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_className << " " << this->_name << " can't attack because it has no hitpoints" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_className << " " << this->_name << " can't attack because it has no energyPoints" << std::endl;
		return;
	}
	else
	{
		this->_energyPoints--;
		std::cout << this->_className << " " << this->_name << " attacks " << target << ", causing "
				  << this->_attackDamage << " points of damage !" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_className << " " << this->_name << " can't attack because it has no hitpoints" << std::endl;
		return;
	}
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << this->_className << " " << this->_name << " takes " << amount
			  << " points of damage! Remaining hitPoints: " << this->_hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << this->_className << " " << this->_name << " can't be repaired because it has no hitpoints" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << this->_className << " " << this->_name << " can't be repaired because it has no energyPoints" << std::endl;
		return;
	}
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << this->_className << " " << this->_name << " is repaired for " << amount
			  << " hit points! Current hitPoints are : " << this->_hitPoints << std::endl;
	}
}
