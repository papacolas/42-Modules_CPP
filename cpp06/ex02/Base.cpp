/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:14:11 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/10 15:15:36 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base::~Base(void)
{}

char	randomLetter()
{
	static bool start = false;
	if (!start)
	{
		std::srand(std::time(NULL));
		start = true;
	}
	return static_cast<char>('A' + (std::rand() % 3));
}

Base	*generate(void)
{
	char	letterBase;

	letterBase = randomLetter();
	std::cout << "The letter randmoly choiced is : " << letterBase << std::endl;
	if (letterBase == 'A')
		return new A();
	else if (letterBase == 'B')
		return new B();
	else
		return new C();
}

void	identify(Base *p)
{
	if (!p)
	{
		std::cout << "Error: NULL pointer" << std::endl;
		return;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "Object pointed by p is type : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object pointed by p is type : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object pointed by p is type : C" << std::endl;
	return;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Object referenced by p is type : A" << std::endl;
		return;
	}
	catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Object referenced by p is type : B" << std::endl;
		return;
	}
	catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Object referenced by p is type : C" << std::endl;
		return;
	}
	catch (std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}


