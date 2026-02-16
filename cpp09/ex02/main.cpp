/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:13:20 by ncrivell          #+#    #+#             */
/*   Updated: 2026/01/21 15:50:46 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <climits>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
#include "PmergeMe.hpp"

static bool	parseArgument(int argc, char **argv, std::vector<int> &numbersInVector, std::deque<int> &numbersInDeque)
{
	for (int i = 1; i < argc; i++)
	{
		std::string number = argv[i];
		for (size_t j = 0; j < number.length(); j++)
		{
			if (!isdigit(number[j]))
			{
				std::cerr << "Error : this argument -->  '" << number << "'  is not a positive digit" << std::endl;
				return false;
			}
		}
		long long value;
		std::istringstream ss(number);
		ss >> value;
		if (value < 0 || value > INT_MAX)
		{
			std::cerr << "Error : this number -->  '" << number << "'  is not an integer" << std::endl;
			return false;
		}
		if (std::find(numbersInVector.begin(), numbersInVector.end(), value) != numbersInVector.end())
		{
			std::cerr << "Error : there is a duplicate value : " << value << std::endl;
			return false;
		}
		numbersInVector.push_back(static_cast<int>(value));
		numbersInDeque.push_back(static_cast<int>(value));
	}
	return true;
}

static void	displayResults(int argc, std::vector<int> &numbersInVector, const std::vector<int> &sorted)
{
	if (argc > 3001)
	{
		std::cout << "Before :  " ;
		for (size_t i = 0; i < 4; ++i)
		{
			std::cout << numbersInVector[i] << " ";
		}

		std::cout << "[...]" << std::endl;

		std::cout << "After :   " ;
		for (size_t i = 0; i < 4; ++i)
		{
			std::cout << sorted[i] << " ";
		}
		std::cout << "[...]" << std::endl;
	}
	else
	{
		std::cout << "Before :  " ;
		for (size_t i = 0; i < numbersInVector.size(); ++i)
		{
			std::cout << numbersInVector[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "After :   " ;
		for (size_t i = 0; i < sorted.size(); ++i)
		{
			std::cout << sorted[i] << " ";
		}
		std::cout << std::endl;
	}
}

int	main(int argc, char**argv)
{
	Pmerge	Ford;
	double	startData = Ford.getTime();
	if (argc < 2)
	{
		std::cerr << "Error : need at least one argument" << std::endl;
		return 1;
	}

	std::vector<int> numbersInVector;
	std::deque<int> numbersInDeque;

	if (!parseArgument(argc, argv, numbersInVector, numbersInDeque))
		return 1;

	double	endData = Ford.getTime();
	double	timeData = endData - startData;


	double	startD = Ford.getTime();
	Ford.makeDequePairs(numbersInDeque);
	double	endD = Ford.getTime();
	double	timeD = endD - startD + timeData;

	double	startV = Ford.getTime();
	Ford.makeVectorPairs(numbersInVector);
	double	endV = Ford.getTime();
	double	timeV = endV - startV + timeData;

	const std::vector<int> &sorted = Ford.getPrincipalVector();
	displayResults(argc, numbersInVector, sorted);

	std::cout << "Time to process a range of " << numbersInDeque.size() <<  " elements with std::deque : " << std::fixed << std::setprecision(5) << timeD / 1000.0 << " ms" << std::endl;
	std::cout << "Time to process a range of " << numbersInVector.size() <<  " elements with std::vector : " << timeV / 1000.0 << " ms" << std::endl;

	return 0;
}
