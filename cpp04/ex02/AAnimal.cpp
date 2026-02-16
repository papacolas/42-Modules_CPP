/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:33:40 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:59:38 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void)
{
	this->type = "animal inconnu";
	std::cout << "AAnimal void constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	this->type = other.getType();
	std::cout << this->type << " AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->type = other.getType();
		std::cout << "AAnimal assignment operator called" << std::endl;
	}
	return *this;
}

std::string	AAnimal::getType(void) const
{
	return this->type;
}

