/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:16:28 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/05 19:06:59 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer::~Serializer(void)
{}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t	temp;

	temp = reinterpret_cast<uintptr_t>(ptr);
	return temp;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *dataTemp;

	dataTemp = reinterpret_cast<Data*>(raw);
	return dataTemp;
}
