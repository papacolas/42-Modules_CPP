/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:43:28 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 13:07:20 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("No_name")
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_className = "FragTrap";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called for : " << name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_className = "FragTrap";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called for : " << other._name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for : " << this->_name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment called for : " << this->_name << " = " << other._name << std::endl;

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

void	FragTrap::attack(const std::string &target)
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

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " says : Hey robots, high fives ??" << std::endl;
}
