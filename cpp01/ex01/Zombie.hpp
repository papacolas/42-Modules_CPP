/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:29:28 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/10 12:49:46 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_01_H
# define ZOMBIE_01_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits.h>
#include <sstream>

class Zombie
{
	private:
		std::string	_name;
		int			_index;

	public:
		Zombie();
		~Zombie(void);
		void	announce() const;
		void	setName(std::string name);
		void	setIndex(int index);
};
Zombie	*zombieHorde(int N, std::string name);

#endif
