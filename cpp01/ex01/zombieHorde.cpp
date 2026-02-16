/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:29:31 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:58 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int i = 0;

	if (N < 1)
	{
		std::cout << "Error : Must contain Zombies !" << std::endl;
		return NULL;
	}

	Zombie	*zombiesHorde = new Zombie[N];
	while (i < N)
	{
		std::cout << "Zombie " << (i + 1) << " created with the name : " << name << std::endl;
		zombiesHorde[i].setName(name);
		zombiesHorde[i].setIndex(i + 1);
		i++;
	}

	return zombiesHorde;
}
