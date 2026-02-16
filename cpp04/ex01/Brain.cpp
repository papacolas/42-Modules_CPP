/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:16:09 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:30:25 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "idea or not idea";
	}
	std::cout << "Brain constructor called" << std::endl;
}
Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	std::cout << "Brain assignment operator called" << std::endl;

	return *this;
}

void	Brain::setIdea(int index, const std::string &idea)
{
	if ( index >= 0 && index < 100)
		_ideas[index] = idea;
	else
		std::cout << "Index trop petit ou trop grand. Doit etre entre 0 et 100" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if ( index >= 0 && index < 100)
		return (this->_ideas[index]);
	else
		std::cout << "Index trop petit ou trop grand. Doit etre entre 0 et 100" << std::endl;
	return std::string();
}

