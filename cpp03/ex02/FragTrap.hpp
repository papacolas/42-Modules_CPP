/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:08:22 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/21 12:39:11 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS
# define FRAGTRAP_CLASS
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap &other);
		FragTrap(const std::string &name);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif
