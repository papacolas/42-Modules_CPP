/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:17:18 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:32:21 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP
#include <string>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const Animal &other);
		virtual	~Animal(void);
		Animal &operator=(const Animal &other);

		virtual void		makeSound(void) const;

		std::string			getType(void) const;
};

#endif
