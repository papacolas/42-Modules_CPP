/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:58:26 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/05 19:11:43 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data	test;
	Data	*ptr_test = &test;
	Data	*ptr_second_test;
	uintptr_t	raw;

	test.age = 41;
	test.name = "nico";

	raw = Serializer::serialize(ptr_test);
	std::cout << "Raw : " << raw << std::endl;

	ptr_second_test = Serializer::deserialize(raw);
	std::cout << "deserialize : " << ptr_second_test << std::endl;

	std::cout << "Verification : pointeur initial = " << ptr_test << std::endl;
	std::cout << "Name = " << ptr_second_test->name << " , age = " << ptr_second_test->age << std::endl;

	return 0;
}
