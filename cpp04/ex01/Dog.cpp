/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:07:51 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 20:33:07 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void)
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog void constructor called" << std::endl;

}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->type = other.getType();
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		Brain *new_brain = new Brain(*other._brain);
		delete this->_brain;
		this->_brain = new_brain;
		std::cout << "Dog assignment operator called" << std::endl;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf Wouf" << std::endl;
}


std::string	Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
