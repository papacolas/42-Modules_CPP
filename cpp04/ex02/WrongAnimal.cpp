/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:34:38 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 13:00:25 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal inconnu";
	std::cout << "WrongAnimal void constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.getType();
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type = other.getType();
		std::cout << "WrongAnimal assignment operator called" << std::endl;
	}
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return this->type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Unknown sound" << std::endl;
}

