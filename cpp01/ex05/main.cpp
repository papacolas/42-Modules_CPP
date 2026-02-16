/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:12:57 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/12 16:01:18 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
	{
		std::cout << "Error: Must have only 2 arguments" << std::endl;
		return 1;
	}
	std::string	input = argv[1];
	if (input == "DEBUG"
		|| input == "INFO"
		|| input == "WARNING"
		|| input == "ERROR")
	{
		harl.complain(input);
	}
	else
	{
		std::cout << "Error: Wrong argument. Must be : DEBUG, INFO, WARNING or ERROR" << std::endl;
		return 1;
	}
	return 0;
}
