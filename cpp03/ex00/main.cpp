/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:35:56 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 14:14:53 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "=== Test 1: Basic attacks ===" << std::endl;

	ClapTrap	mamieNova("mamieNova");
	mamieNova.attack("Radio_Nova");
	mamieNova.takeDamage(5);
	mamieNova.beRepaired(2);

	std::cout << "\n=== Test 2: mamieNova leaves us ===" << std::endl;

	mamieNova.attack("papiBrossard");
	mamieNova.takeDamage(8);
	mamieNova.attack("pereCastor");
	mamieNova.beRepaired(1);

	std::cout << "\n=== Test 3: Copy-Constructor ===" << std::endl;

	ClapTrap	oncleBens("oncleBens");
	ClapTrap	oncleBens_copy(oncleBens);
	oncleBens_copy.attack("oncleSam");

	std::cout << "\n=== Test 4: Energy fall ===" << std::endl;

	ClapTrap	msfubc("mamie_sait_faire_un_bon_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");
	msfubc.attack("papi_n_aime_pas_le_cafe");

	std::cout << "\n=== Test 5: Assignment constructor ===" << std::endl;

	ClapTrap	mamieGaga("mamieGaga");
	ClapTrap	ladyGaga("ladyGaga");
	ladyGaga = mamieGaga;
	ladyGaga.attack("RadioGaga");

	std::cout << "\n=== Test 6: The destructors ===" << std::endl;

	return 0;
}

