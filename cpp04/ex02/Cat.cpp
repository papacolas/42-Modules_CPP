/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:34:04 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 20:34:42 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : _brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat void constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	this->type = other.getType();
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		Brain *new_brain = new Brain(*other._brain);
		delete this->_brain;
		this->_brain = new_brain;
		std::cout << "Cat assignment operator called" << std::endl;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

std::string	Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
