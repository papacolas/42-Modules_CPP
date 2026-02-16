/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:34:16 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 20:35:31 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void) : _brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog void constructor called" << std::endl;

}

Dog::Dog(const Dog &other) : AAnimal(other)
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
		AAnimal::operator=(other);
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
