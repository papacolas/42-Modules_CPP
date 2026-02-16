/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:14:16 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 20:53:23 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
