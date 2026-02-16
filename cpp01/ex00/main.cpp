/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:49:02 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/12 18:49:33 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "=== Creating heap zombie ===" << std::endl;
	Zombie *heapZombie = newZombie("HeapZ");

	heapZombie->announce();

	std::cout << "\n=== Creating stack zombie ===" << std::endl;
	randomChump("StackZ");

	std::cout << "=== After randomChump() ===" << std::endl;
	std::cout << "\n=== Deleting heap zombie ===" << std::endl;
	delete heapZombie;
	std::cout << "\n=== End of main ===" << std::endl;
	return (0);
}
