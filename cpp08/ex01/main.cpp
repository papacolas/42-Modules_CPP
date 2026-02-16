/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:37:09 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/18 11:31:08 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <ctime>
#include <algorithm>
#include <vector>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;


	try {
		Span small(2);
		small.addNumber(1);
		small.addNumber(2);
		small.addNumber(3);
	} catch (const std::exception &e) {
		std::cout << "Exception : Span is full" << std::endl;
	}

	std::cout << std::endl;


	try {
		Span empty(5);
		empty.addNumber(42);
		std::cout << empty.shortestSpan();
	} catch (const std::exception &e) {
		std::cout << "Exception : Not enough elements to calculate span" << std::endl;
	}

	std::cout << std::endl;


	// Span test = Span(1000000);
	// std::vector<int> big;
	// for (size_t i = 0; i < 1000000; i++)
	// {
	// 	big.push_back(i);
	// }
	// test.addMultipleNumbers(big.begin(), big.end());
	// std::cout << test.shortestSpan() << std::endl;
	// std::cout << test.longestSpan() << std::endl;

	std::srand(std::time(0));
	std::vector<int> big(1000);
	std::generate(big.begin(), big.end(), std::rand);
	std::sort(big.begin(), big.end());
	std::vector<int>::iterator new_end = std::unique(big.begin(), big.end());
	big.erase(new_end, big.end());
	Span test(big.size());
	test.addMultipleNumbers(big.begin(), big.end());
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	return 0;
}
