/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:22:40 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 14:25:06 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== Test 1: Basic attacks ===" << std::endl;

	// ClapTrap	mamieNova("mamieNova");
	// mamieNova.attack("Radio_Nova");
	// mamieNova.takeDamage(5);
	// mamieNova.beRepaired(2);

	std::cout << std::endl;

	ScavTrap	picasso("picasso");
	picasso.attack("monet");
	picasso.takeDamage(4);
	picasso.beRepaired(2);
	picasso.guardGate();

	std::cout << "\n=== Test 2: mamieNova leaves us ===" << std::endl;

	// mamieNova.attack("papiBrossard");
	// mamieNova.takeDamage(8);
	// mamieNova.attack("pereCastor");
	// mamieNova.beRepaired(1);

	std::cout << std::endl;

	picasso.attack("Bonnard");
	picasso.takeDamage(10);
	picasso.attack("Van_Gogh");
	picasso.beRepaired(2);

	std::cout << "\n=== Test 3: Copy-Constructor ===" << std::endl;

	// ClapTrap	oncleBens("oncleBens");
	// ClapTrap	oncleBens_copy(oncleBens);
	// oncleBens_copy.attack("oncleSam");

	std::cout << std::endl;

	ScavTrap	manet("manet");
	ScavTrap	manet_copy(picasso);
	manet_copy.attack("Rembrandt");

	std::cout << "\n=== Test 4: Energy fall ===" << std::endl;

	// ClapTrap	msfubc("mamie_sait_faire_un_bon_cafe");
	// for (int i = 0; i < 12; i++)
	// 	msfubc.attack("papi_n_aime_pas_le_cafe");

	std::cout << std::endl;

	ScavTrap	lajoconde("La_Joconde");
	for (int i = 0; i < 55; i++)
		lajoconde.attack("Leonard");

	std::cout << "\n=== Test 5: Assignment constructor ===" << std::endl;

	// ClapTrap	mamieGaga("mamieGaga");
	// ClapTrap	ladyGaga("ladyGaga");
	// ladyGaga = mamieGaga;
	// ladyGaga.attack("RadioGaga");

	std::cout << std::endl;

	ScavTrap	dali("Dali");
	ScavTrap	chagall("Chagall");
	chagall = dali;
	chagall.attack("Chabal");

	std::cout << "\n=== Test 6: The destructors ===" << std::endl;

	return 0;
}


