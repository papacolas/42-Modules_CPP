/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:48:49 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/10 10:37:34 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		void	announce(void)const;
		Zombie(std::string zombieName);
		~Zombie(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
