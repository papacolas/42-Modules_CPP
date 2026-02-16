/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:37:13 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/18 11:36:30 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(void)
{
	_N = 0;
}

Span::Span(unsigned int N)
{
	_vect.reserve(N);
	_N = N;
}

Span::Span(const Span &other)
{
	this->_N = other._N;
	this->_vect = other._vect;
}

Span::~Span()
{}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_vect = other._vect;
	}
	return(*this);
}

void Span::addNumber(int num)
{
	if (_vect.size() < _N)
		_vect.push_back(num);
	else
		throw std::exception();
}


unsigned int Span::shortestSpan()
{
	if (_vect.size() < 2)
		throw std::exception();

	std::vector<int> temp = _vect;
	std::sort(temp.begin(), temp.end());
	unsigned int space = temp[1] - temp[0];
	for (size_t i = 0; i < temp.size() - 1 ; ++i)
	{
		unsigned int difference = temp[i + 1] - temp[i];
		if (difference < space)
		{
			space = difference;
		}
	}
	return (space);
}

unsigned int Span::longestSpan()
{
	int min = *std::min_element(_vect.begin(), _vect.end());
	int max = *std::max_element(_vect.begin(), _vect.end());

	return (max - min);
}


