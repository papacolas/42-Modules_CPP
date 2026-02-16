/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:08:16 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 14:29:12 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << std::endl;

	FragTrap	r2d2("R2D2");
	r2d2.attack("C3PO");
	r2d2.takeDamage(20);
	r2d2.beRepaired(10);
	r2d2.highFivesGuys();

	std::cout << "\n=== Test 2: mamieNova leaves us ===" << std::endl;

	// mamieNova.attack("papiBrossard");
	// mamieNova.takeDamage(8);
	// mamieNova.attack("pereCastor");
	// mamieNova.beRepaired(1);

	// std::cout << std::endl;

	// picasso.attack("Bonnard");
	// picasso.takeDamage(10);
	// picasso.attack("Van_Gogh");
	// picasso.beRepaired(2);

	std::cout << std::endl;

	r2d2.attack("BB8");
	r2d2.takeDamage(90);
	r2d2.attack("K2SO");
	r2d2.beRepaired(5);

	std::cout << "\n=== Test 3: Copy-Constructor ===" << std::endl;

	// ClapTrap	oncleBens("oncleBens");
	// ClapTrap	oncleBens_copy(oncleBens);
	// oncleBens_copy.attack("oncleSam");

	// std::cout << std::endl;

	// ScavTrap	manet("manet");
	// ScavTrap	manet_copy(picasso);
	// manet_copy.attack("Rembrandt");

	std::cout << std::endl;

	FragTrap	walle("WALL-E");
	FragTrap	walle_copy(walle);
	walle_copy.attack("Trooper");

	std::cout << "\n=== Test 4: Energy fall ===" << std::endl;

	// ClapTrap	msfubc("mamie_sait_faire_un_bon_cafe");
	// for (int i = 0; i < 12; i++)
	// 	msfubc.attack("papi_n_aime_pas_le_cafe");

	// std::cout << std::endl;

	// ScavTrap	lajoconde("La_Joconde");
	// for (int i = 0; i < 55; i++)
	// 	lajoconde.attack("Leonard");

	std::cout << std::endl;

	FragTrap	optimus("OptimusPrime");
	for (int i = 0; i < 105; i++)
		optimus.attack("Megatron");

	std::cout << "\n=== Test 5: Assignment constructor ===" << std::endl;

	// ClapTrap	mamieGaga("mamieGaga");
	// ClapTrap	ladyGaga("ladyGaga");
	// ladyGaga = mamieGaga;
	// ladyGaga.attack("RadioGaga");

	// std::cout << std::endl;

	// ScavTrap	dali("Dali");
	// ScavTrap	chagall("Chagall");
	// chagall = dali;
	// chagall.attack("Chabal");

	std::cout << std::endl;

	FragTrap	bender("Bender");
	FragTrap	calculon("Calculon");
	calculon = bender;
	calculon.attack("Flexo");
	calculon.highFivesGuys();

	std::cout << "\n=== Test 6: The destructors ===" << std::endl;

	return 0;
}


