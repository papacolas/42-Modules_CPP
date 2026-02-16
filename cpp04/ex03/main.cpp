/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:10:30 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 13:19:48 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	std::cout << std::endl;

	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* me = new Character("me");
	std::cout << std::endl;

	AMateria* tmp;
	std::cout << std::endl;

	tmp = src->createMateria("ice");
	std::cout << std::endl;

	me->equip(tmp);
	std::cout << std::endl;

	tmp = src->createMateria("cure");
	std::cout << std::endl;

	me->equip(tmp);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	std::cout << std::endl;

	me->use(0, *bob);
	std::cout << std::endl;

	me->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	std::cout << std::endl;

	delete me;
	std::cout << std::endl;

	delete src;
	return 0;
}
