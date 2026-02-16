/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:29:15 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/10 12:45:49 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	list_the_zombies(Zombie *horde_of_zombies, int size)
{
	int	i = 0;

	while (i < size)
	{
		horde_of_zombies[i].announce();
		i++;
	}
}

int	main(void)
{
	Zombie		*horde_of_zombies;
	int			zombiesTotal = 4;
	std::string	zombiesName = "Zumba";

	horde_of_zombies = zombieHorde(zombiesTotal, zombiesName);

	list_the_zombies(horde_of_zombies, zombiesTotal);
	
	delete[] horde_of_zombies;
	return (0);
}
