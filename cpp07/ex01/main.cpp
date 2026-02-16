/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:27:25 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/11 15:35:56 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename L>
void	fooVoid(L const &element)
{
	static int i = 0;

	std::cout << element << "  ";
	if (i == 3)
	{
		std::cout << std::endl;
		return;
	}
	i++;
}
template<typename L>
void	fooDoubleValue(L &element)
{
	static int i = 0;
	L mult = element * 2;
	if (i == 0)
		std::cout << "The values are multiplicated by 2 ! :" << std::endl;
	std::cout << element << " * 2 = " << mult << "  ";
	if (i == 3)
	{
		std::cout << std::endl;
		return;
	}
	i++;
}
template<typename L>
void	fooUpperCase(L &element)
{
	if (element >= 'a' && element <= 'z')
		std::cout << element << " -> " << (char)(element - 32) << "  ";
}

template<typename L>
void	fooUpperCaseString(L &element)
{
	int len = element.length();

	for (int i = 0; i < len; i++)
	{
		if (element[i] >= 'a' && element[i] <= 'z')
			std::cout << (char)(element[i] - 32);
	}
	std::cout << std::endl;
}


int main(void)
{
	int			arrayInt[4] = {1, 2, 3, 4};
	char		arrayChar[4] = {'a', 'b', 'c', 'd'};
	double		arrayDouble[4] = {5.5, 6.6, 7.7, 8.8};
	float		arrayFloat[4] = {1.1, 2.2, 3.3, 4.4};
	std::string	arrayStr[4] = {"hello", "coucou", "youpi", "youpla"};

	std::cout << "===== Printed values =====" << std::endl;
	iter(arrayInt, 4, fooVoid<const int>);
	std::cout << std::endl;
	iter(arrayChar, 4, fooVoid<const char>);
	std::cout << std::endl;
	iter(arrayDouble, 4, fooVoid<const double>);
	std::cout << std::endl;
	iter(arrayFloat, 4, fooVoid<const float>);
	std::cout << std::endl;
	iter(arrayStr, 4, fooVoid<std::string const>);
	std::cout << std::endl;

	std::cout << "===== Double values =====" << std::endl;
	iter(arrayInt, 4, fooDoubleValue<int>);
	iter(arrayDouble, 4, fooDoubleValue<double>);
	iter(arrayFloat, 4, fooDoubleValue<float>);
	std::cout << std::endl;

	std::cout << "===== Upper char values =====" << std::endl;
	iter(arrayChar, 4, fooUpperCase<char>);
	std::cout << std::endl;
	iter(arrayStr, 4, fooUpperCaseString<std::string>);

}
