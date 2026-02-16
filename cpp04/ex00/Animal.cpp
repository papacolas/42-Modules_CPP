/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:17:21 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:32:26 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	this->type = "animal inconnu";
	std::cout << "Animal void constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->type = other.getType();
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.getType();
		std::cout << "Animal assignment operator called" << std::endl;
	}
	return *this;
}

std::string	Animal::getType(void) const
{
	return this->type;
}

void	Animal::makeSound() const
{
	std::cout << "Unknown sound" << std::endl;
}
