/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:43:19 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 13:09:52 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS
# define CLAPTRAP_CLASS
#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string			_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;
		std::string	_className;

	public:
		//Constructeurs-Destructeur
		ClapTrap(void);
		ClapTrap(const ClapTrap &other);
		ClapTrap(const std::string &name);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &other);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
