/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:43:40 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 13:05:18 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("No_name")
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_className = "ScavTrap";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for : " << name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_className = "ScavTrap";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called for : " << other._name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for : " << this->_name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assignment called for : " << this->_name << " = " << other._name << std::endl;

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

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack because it has no hitpoints" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack because it has no energyPoints" << std::endl;
		return;
	}
	else
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
				  << this->_attackDamage << " points of damage !" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
	std::cout << "It will win 2 points of energy during this mission" << std::endl;
	std::cout << "ScavTrap " << this->_name << " has " << this->_energyPoints << " point of energy" << std::endl;
	this->_energyPoints += 2;
	std::cout << "ScavTrap " << this->_name << " win 2 points of energy "
			  << " Now it has : " << this->_energyPoints << " points of energy" << std::endl;
}
