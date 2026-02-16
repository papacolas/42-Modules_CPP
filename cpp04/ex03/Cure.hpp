/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:19:25 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 20:53:00 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_CLASS_HPP
# define Cure_CLASS_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);

		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
