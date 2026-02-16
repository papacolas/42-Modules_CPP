/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:34:27 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 13:01:52 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	static const char* RESET  = "\033[0m";
	static const char* GREEN  = "\033[32m";
	// static const char* YELLOW = "\033[33m";
	// static const char* CYAN   = "\033[36m";
	// static const char* RED    = "\033[31m";


	std::cout << GREEN << "--------Creation classes--------" << RESET << std::endl;

	Dog	basic;
	Dog tmp = basic;

	std::cout << std::endl;

	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	std::cout << std::endl;
	std::cout << GREEN << "--------DELETE--------" << RESET << std::endl;
	delete j;
	delete i;

	std::cout << std::endl;

	std::cout << GREEN << "--------Creation tableau avec juste Dog--------" << RESET << std::endl;

	AAnimal *tab[4];
	for (int i = 0; i < 4; i++)
		tab[i] = new Dog();
	std::cout << std::endl;
	for (int j = 0; j < 4; j++)
		tab[j]->makeSound();
	std::cout << std::endl;
	for (int k = 0; k < 4; k++)
		delete tab[k];

	std::cout << std::endl;
	std::cout << GREEN << "--------Creation tableau 50/50--------" << RESET << std::endl;
	AAnimal *tab_mixt[4];
	for (int i = 0; i < 2; i++)
		tab_mixt[i] = new Dog();
	for (int j = 2; j < 4; j++)
		tab_mixt[j] = new Cat();
	std::cout << std::endl;
	for (int m = 0; m < 4; m++)
		tab_mixt[m]->makeSound();
	std::cout << std::endl;
	for (int k = 0; k < 4; k++)
		delete tab_mixt[k];
	std::cout << std::endl;
	return 0;
}
