/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:13:24 by ncrivell          #+#    #+#             */
/*   Updated: 2026/01/21 15:52:48 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

Pmerge::Pmerge(void)
{}

Pmerge::Pmerge(const Pmerge &other)
{
	this->_pairsVector = other._pairsVector;
	this->_principalVector = other._principalVector;
	this->_minimalVector = other._minimalVector;
	this->_pairsDeque = other._pairsDeque;
	this->_principalDeque = other._principalDeque;
	this->_minimalDeque = other._minimalDeque;
}

Pmerge::~Pmerge(void)
{}

Pmerge &Pmerge::operator=(const Pmerge &other)
{
	if (this != &other)
	{
		this->_pairsVector = other._pairsVector;
		this->_principalVector = other._principalVector;
		this->_minimalVector = other._minimalVector;
		this->_pairsDeque = other._pairsDeque;
		this->_principalDeque = other._principalDeque;
		this->_minimalDeque = other._minimalDeque;
	}
	return(*this);
}


double	Pmerge::getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000.0 + tv.tv_usec;

}


const std::vector<int> &Pmerge::getPrincipalVector() const
{
	return this->_principalVector;
}

const std::deque<int> &Pmerge::getPrincipalDeque() const
{
	return this->_principalDeque;
}

std::vector<size_t> Pmerge::jacobsthalSuite(size_t minimal)
{
	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	size_t after = 1;
	while (after < minimal)
	{
		after = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(after);
	}

	return jacob;
}

std::deque<size_t> Pmerge::jacobsthalSuiteDeque(size_t minimal)
{
	std::deque<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	size_t after = 1;
	while (after < minimal)
	{
		after = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(after);
	}

	return jacob;
}

std::vector<size_t> Pmerge::insertionOrder(size_t n)
{
	if (n == 0)
		return std::vector<size_t>();

	std::vector<size_t> jacobsthal = jacobsthalSuite(n);
	std::vector<size_t> result;
	std::vector<bool> used(n, false);

	result.push_back(0);
	used[0] = true;

	if (n > 1)
	{
		result.push_back(1);
		used[1] = true;
	}

	for (size_t i = 3; i < jacobsthal.size(); ++i)
	{
		size_t	current = jacobsthal[i];
		size_t	before = jacobsthal[i - 1];

		if (current >= n)
			current = n - 1;
		if (before >= n)
			break;

		for (size_t j = current; j > before; --j)
		{
			if (!used[j])
			{
				result.push_back(j);
				used[j] = true;
			}
		}

		if (current >= n - 1)
			break;
	}

	for (size_t i = 0; i < n; ++i)
	{
		if (!used[i])
			result.push_back(i);
	}

	return result;
}

std::deque<size_t> Pmerge::insertionOrderDeque(size_t n)
{
	if (n == 0)
		return std::deque<size_t>();

	std::deque<size_t> jacobsthal = jacobsthalSuiteDeque(n);
	std::deque<size_t> result;
	std::vector<bool> used(n, false);

	result.push_back(0);
	used[0] = true;

	if (n > 1)
	{
		result.push_back(1);
		used[1] = true;
	}

	for (size_t i = 3; i < jacobsthal.size(); ++i)
	{
		size_t	current = jacobsthal[i];
		size_t	before = jacobsthal[i - 1];

		if (current >= n)
			current = n - 1;
		if (before >= n)
			break;

		for (size_t j = current; j > before; --j)
		{
			if (!used[j])
			{
				result.push_back(j);
				used[j] = true;
			}
		}

		if (current >= n - 1)
			break;
	}

	for (size_t i = 0; i < n; ++i)
	{
		if (!used[i])
			result.push_back(i);
	}

	return result;
}


void	Pmerge::makeVectorPairs(const std::vector<int> &numbersInVector)
{
	_pairsVector.clear();
	_principalVector.clear();
	_minimalVector.clear();

	for (size_t i = 0; i + 1 < numbersInVector.size(); i+=2)
	{
		std::pair <int, int> temp;
		if (numbersInVector[i] > numbersInVector[i + 1])
		{
			temp = std::make_pair(numbersInVector[i], numbersInVector[i + 1]);
		}
		else
		{
			temp = std::make_pair(numbersInVector[i + 1], numbersInVector[i]);
		}
		_pairsVector.push_back(temp);
		_principalVector.push_back(temp.first);
		_minimalVector.push_back(temp.second);
	}
	if (numbersInVector.size() % 2 != 0)
		_principalVector.push_back(numbersInVector.back());

	_principalVector = fordSortVector(_principalVector);

	std::vector<size_t> order = insertionOrder(_minimalVector.size());

	for (size_t i = 0; i < _minimalVector.size(); ++i)
	{
		size_t index = order[i];
		std::vector<int>::iterator pos = std::lower_bound(_principalVector.begin(), _principalVector.end(), _minimalVector[index]);
		_principalVector.insert(pos, _minimalVector[index]);
	}
}


void	Pmerge::makeDequePairs(const std::deque<int> &numbersInDeque)
{
	_pairsDeque.clear();
	_principalDeque.clear();
	_minimalDeque.clear();

	for (size_t i = 0; i + 1 < numbersInDeque.size(); i+=2)
	{
		std::pair<int, int> temp;
		if (numbersInDeque[i] > numbersInDeque[i + 1])
			temp = std::make_pair(numbersInDeque[i], numbersInDeque[i + 1]);
		else
			temp = std::make_pair(numbersInDeque[i + 1], numbersInDeque[i]);
		_pairsDeque.push_back(temp);
		_principalDeque.push_back(temp.first);
		_minimalDeque.push_back(temp.second);
	}

	if (numbersInDeque.size() % 2 != 0)
		_principalDeque.push_back(numbersInDeque.back());
		
	_principalDeque = fordSortDeque(_principalDeque);

	std::deque<size_t> order = insertionOrderDeque(_minimalDeque.size());

	for (size_t i = 0; i < _minimalDeque.size(); ++i)
	{
		size_t index = order[i];
		std::deque<int>::iterator pos = std::lower_bound(_principalDeque.begin(), _principalDeque.end(), _minimalDeque[index]);
		_principalDeque.insert(pos, _minimalDeque[index]);
	}
}


std::vector<int> Pmerge::fordSortVector(std::vector<int> pVector)
{
	if (pVector.size() < 2)
		return pVector;

	std::vector< std::pair<int, int> >	pairsToSort;
	std::vector<int>					biggest;
	std::vector<int>					smallest;
	int									impairElement = 0;

	for (size_t i = 0; i + 1 < pVector.size(); i+=2)
	{
		std::pair <int, int> temp;
		if (pVector[i] > pVector[i + 1])
		{
			temp = std::make_pair(pVector[i], pVector[i + 1]);
		}
		else
		{
			temp = std::make_pair(pVector[i + 1], pVector[i]);
		}
		pairsToSort.push_back(temp);
		biggest.push_back(temp.first);
		smallest.push_back(temp.second);
	}

	if (pVector.size() % 2 != 0)
	{
		impairElement = pVector.back();
	}

	biggest = fordSortVector(biggest);


	std::vector<size_t> order = insertionOrder(smallest.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t index = order[i];
		std::vector<int>::iterator pos = std::lower_bound(biggest.begin(), biggest.end(), smallest[index]);
		biggest.insert(pos, smallest[index]);
	}

	if (pVector.size() % 2 != 0)
	{
		std::vector<int>::iterator pos = std::lower_bound(biggest.begin(), biggest.end(), impairElement);
		biggest.insert(pos, impairElement);
	}

	return biggest;
}


std::deque<int> Pmerge::fordSortDeque(std::deque<int> pDeque)
{
	if (pDeque.size() < 2)
		return pDeque;

	std::deque< std::pair<int, int> >	pairsToSort;
	std::deque<int>						biggest;
	std::deque<int>						smallest;
	int									impairElement = 0;

	for (size_t i = 0; i + 1 < pDeque.size(); i+=2)
	{
		std::pair <int, int> temp;
		if (pDeque[i] > pDeque[i + 1])
		{
			temp = std::make_pair(pDeque[i], pDeque[i + 1]);
		}
		else
		{
			temp = std::make_pair(pDeque[i + 1], pDeque[i]);
		}
		pairsToSort.push_back(temp);
		biggest.push_back(temp.first);
		smallest.push_back(temp.second);
	}

	if (pDeque.size() % 2 != 0)
	{
		impairElement = pDeque.back();
	}

	biggest = fordSortDeque(biggest);


	std::deque<size_t> order = insertionOrderDeque(smallest.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t index = order[i];
		std::deque<int>::iterator pos = std::lower_bound(biggest.begin(), biggest.end(), smallest[index]);
		biggest.insert(pos, smallest[index]);
	}

	if (pDeque.size() % 2 != 0)
	{
		std::deque<int>::iterator pos = std::lower_bound(biggest.begin(), biggest.end(), impairElement);
		biggest.insert(pos, impairElement);
	}

	return biggest;
}
