/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:08:06 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 12:36:22 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string.h>
#include <iostream>

class ScavTrap : public ClapTrap
{
		public:
		ScavTrap(void);
		ScavTrap(const ScavTrap &other);
		ScavTrap(const std::string &name);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void	attack(const std::string &target);
		void	guardGate();
};

#endif
