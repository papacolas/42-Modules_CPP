/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:35:36 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/10 15:06:49 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "----- Be careful, the good format is : ./convert and only one arg -----" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
	//(void)argc;
	//(void)argv;
	// std::cout << "=== Test 1: char 'a'===" << std::endl;
	// ScalarConverter::convert("'a'");

	// std::cout << "\n=== Test 2: int 28 ===" << std::endl;
	// ScalarConverter::convert("28");

	// std::cout << "\n=== Test 3: float 28.0f ===" << std::endl;
	// ScalarConverter::convert("28.0f");

	// std::cout << "\n=== Test 4: double 28.0 ===" << std::endl;
	// ScalarConverter::convert("28.0");

	// std::cout << "\n=== Test 5: zero 0 ===" << std::endl;
	// ScalarConverter::convert("0");

	// std::cout << "\n=== Test 6: nanf ===" << std::endl;
	// ScalarConverter::convert("nanf");

	// std::cout << "\n=== Test 7: nan ===" << std::endl;
	// ScalarConverter::convert("nan");

	// std::cout << "\n=== Test 8: +inff ===" << std::endl;
	// ScalarConverter::convert("+inff");

	// std::cout << "\n=== Test 8bis: +inf ===" << std::endl;
	// ScalarConverter::convert("+inf");

	// std::cout << "\n=== Test 9: -inf ===" << std::endl;
	// ScalarConverter::convert("-inf");

	// std::cout << "\n=== Test 9bis: inf ===" << std::endl;
	// ScalarConverter::convert("inf");

	// std::cout << "\n=== Test 10: overflow int 99999999999999999 ===" << std::endl;
	// ScalarConverter::convert("99999999999999999");

	// std::cout << "\n=== Test 11: negative -28 ===" << std::endl;
	// ScalarConverter::convert("-28");

	// std::cout << "\n=== Test 12: negative float -4.3f ==" << std::endl;
	// ScalarConverter::convert("-4.3f");

	return 0;

}
