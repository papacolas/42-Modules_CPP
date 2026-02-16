/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:24:51 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:32:36 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat void constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->type = other.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.getType();
		std::cout << "Cat assignment opertor called" << std::endl;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
