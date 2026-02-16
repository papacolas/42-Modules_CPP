/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:58:34 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/10 16:54:41 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(std::string const &type);
	~Weapon();
	const std::string &getType(void) const;
	void			  setType(std::string const &type);
};

#endif
