/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:08:13 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/22 17:35:28 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : must have only 2 arguments" << std::endl;
		return 1;
	}

	std::string input = argv[1];
	std::size_t found = input.find_first_not_of(" 0123456789+-*/");
	if (found != std::string::npos)
	{
		std::cout << "Error : the charactere " << input[found] <<" is not authorized" << std::endl;
		return 1;
	}

	RPN polish(input);
	polish.calculator();

	return 0;
}
