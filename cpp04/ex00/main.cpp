/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:17:16 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:33:31 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{

static const char* RESET  = "\033[0m";
static const char* GREEN  = "\033[32m";
// static const char* YELLOW = "\033[33m";
// static const char* CYAN   = "\033[36m";
static const char* RED    = "\033[31m";


std::cout << GREEN << "--------Creation classes--------" << RESET << std::endl;
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << GREEN << "--------Types--------" << RESET << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;

std::cout << GREEN << "--------Sounds--------" << RESET << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();

std::cout<< std::endl;

std::cout << RED << "/////WRONG ANIMAL/////" << RESET << std::endl;
std::cout << GREEN << "--------Creation classes--------" << RESET << std::endl;

const WrongAnimal* bad = new WrongAnimal();
const WrongAnimal* k = new WrongCat();

std::cout << GREEN << "--------Type--------" << RESET << std::endl;
std::cout << k->getType() << " " << std::endl;

std::cout << GREEN << "--------Sounds--------" << RESET << std::endl;
k->makeSound();
bad->makeSound();

std::cout << GREEN << "--------DELETE--------" << RESET << std::endl;

delete meta;
delete i;
delete j;
delete bad;
delete k;

return 0;
}
