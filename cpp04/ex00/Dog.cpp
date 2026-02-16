/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:24:17 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:32:47 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog void constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.getType();
		std::cout << "Dog assignment opertor called" << std::endl;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf Wouf" << std::endl;
}
