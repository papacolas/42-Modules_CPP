/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:00:20 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/18 11:11:19 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
	std::vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);

	std::cout << "Contenu du vecteur : " << std::endl;
	for (size_t i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << " / ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "----- test avec la valeur 2 -----" << std::endl;
		easyfind(test, 2);
		std::cout << "----- test avec la valeur 8 -----" << std::endl;
		easyfind(test, 8);
	} catch (const std::exception &e) {
		std::cout << "Occurence didn't find ..." << std::endl;
	}

	std::cout << std::endl;

	std::list<int> lst;
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(8);
	lst.push_back(9);
	lst.push_back(10);

	std::cout << "Contenu de la liste : " << std::endl;
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " / ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "----- test avec la valeur 9 -----" << std::endl;
		easyfind(lst, 9);
		std::cout << "----- test avec la valeur 2 -----" << std::endl;
		easyfind(lst, 2);
	} catch (const std::exception &e) {
		std::cout << "Occurence didn't find ..." << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	std::cout << "Contenu du deque : " << std::endl;
	for (std::deque<int>::const_iterator it = dq.begin(); it != dq.end(); ++it)
	{
		std::cout << *it << " / ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	try {
		std::cout << "----- test avec la valeur 2 -----" << std::endl;
		easyfind(dq, 2);
		std::cout << "----- test avec la valeur 9 -----" << std::endl;
		easyfind(dq, 9);
	} catch (const std::exception &e) {
		std::cout << "Occurence didn't find ..." << std::endl;
	}
	return 0;
}
