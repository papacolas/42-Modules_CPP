/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:33:46 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:59:33 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AANIMAL_CLASS_HPP
# define AANIMAL_CLASS_HPP
#include <string>

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal(void);
		AAnimal(const AAnimal &other);
		virtual	~AAnimal(void);
		AAnimal &operator=(const AAnimal &other);

		virtual void		makeSound(void) const = 0;

		std::string			getType(void) const;
};

#endif
