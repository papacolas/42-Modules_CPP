/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:30:24 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:31:48 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat void constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->type = other.getType();
		std::cout << "WrongCat assignment opertor called" << std::endl;
	}
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
