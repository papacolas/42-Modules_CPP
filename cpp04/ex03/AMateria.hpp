/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:43:08 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 13:18:43 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_HPP
#define AMATERIA_CLASS_HPP
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string const type;
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		virtual ~AMateria(void);
		AMateria &operator=(const AMateria &other);
		std::string const &getType() const;

		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
