/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:38:15 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/12 16:38:46 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	std::cout << "=== Test 1: tableau vide ===" << std::endl;
	Array<int> empty;
	std::cout << "Taille: " << empty.size() << std::endl;

	std::cout << "\n=== Test 2: tableau taille 5 ===" << std::endl;
	Array<int> arr(5);
	std::cout << "Taille: " << arr.size() << std::endl;

	std::cout << "\n=== Test 3: Remplissage ===" << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;

	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

	std::cout << "\n=== Test 4: Copie ===" << std::endl;
	Array<int> copy = arr;
	std::cout << "Original arr[0] = " << arr[0] << std::endl;
	std::cout << "Copie copy[0] = " << copy[0] << std::endl;

	copy[0] = 999;
	std::cout << "Apres modification:" << std::endl;
	std::cout << "Original arr[0] = " << arr[0] << std::endl;
	std::cout << "Copie copy[0] = " << copy[0] << std::endl;

	std::cout << "\n=== Test 5: Exception hors limites ===" << std::endl;
	try {
		arr[100] = 42;
	}
	catch (const std::exception &e) {
		std::cout << "Exception attrapee: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Differents types ===" << std::endl;
	Array<std::string> strings(4);
	strings[0] = "Comment";
	strings[1] = "est";
	strings[2] = "votre";
	strings[3] = "blanquette ?";

	std::cout << "Strings: ";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << strings[i] << " ";
	std::cout << std::endl;

	Array<double> doubles(3);
	doubles[0] = 3.14;
	doubles[1] = 2.71;
	doubles[2] = 1.41;
	std::cout << "Doubles: ";
	for (unsigned int i = 0; i < doubles.size(); i++)
		std::cout << doubles[i] << " ";
	std::cout << std::endl;

	Array<char> chars(3);
	chars[0] = 'A';
	chars[1] = 'B';
	chars[2] = 'C';
	std::cout << "Chars: ";
	for (unsigned int i = 0; i < chars.size(); i++)
		std::cout << chars[i] << " ";
	std::cout << std::endl;
}


