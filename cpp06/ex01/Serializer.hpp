/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:16:25 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/10 15:35:33 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP
#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data
{
	int			age;
	std::string	name;
} Data;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		~Serializer(void);
		Serializer &operator=(const Serializer &other);

	public:
		static	uintptr_t	serialize(Data *ptr);
		static	Data	*deserialize(uintptr_t raw);
};

#endif
