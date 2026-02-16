/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:43:35 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 15:01:28 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Test 1: Basic attacks ===" << std::endl;

	// ClapTrap	mamieNova("mamieNova");
	// mamieNova.attack("Radio_Nova");
	// mamieNova.takeDamage(5);
	// mamieNova.beRepaired(2);

	// std::cout << std::endl;

	// ScavTrap	picasso("picasso");
	// picasso.attack("monet");
	// picasso.takeDamage(4);
	// picasso.beRepaired(2);
	// picasso.guardGate();

	// std::cout << std::endl;

	// FragTrap	r2d2("R2D2");
	// r2d2.attack("C3PO");
	// r2d2.takeDamage(20);
	// r2d2.beRepaired(10);
	// r2d2.highFivesGuys();

	std::cout << std::endl;

	DiamondTrap diamond("Shiny");
	diamond.attack("Darkness");
	diamond.takeDamage(15);
	diamond.beRepaired(5);
	diamond.whoAmI();

	std::cout << "\n=== Test 2: Copy-Constructor ===" << std::endl;

	DiamondTrap diamondCopy(diamond);
	diamondCopy.whoAmI();
	diamondCopy.ScavTrap::attack("CopyTarget");

	std::cout << "\n=== Test 3: Assignment operator ===" << std::endl;

	DiamondTrap diamond2("AnotherOne");
	diamond2 = diamond;
	diamond2.whoAmI();
	diamond2.attack("AssignmentTarget");

	std::cout << "\n=== Test 4: DiamondTrap special ===" << std::endl;

	diamond.guardGate();		// hérité de ScavTrap
	diamond.highFivesGuys();	// hérité de FragTrap

	std::cout << "\n=== Test 5: Destructors ===" << std::endl;

	return 0;
}
