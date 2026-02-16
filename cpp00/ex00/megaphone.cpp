/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:24:08 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/07 16:29:22 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	int	i = 1;
	int j = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc > 1)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				argv[i][j] = std::toupper(static_cast<unsigned char>(argv[i][j]));
				std::cout << argv[i][j];
				j++;
			}
			if (i < argc - 1)
				std::cout << " ";
			i++;
		}
	}
	std::cout << std::endl;
	return 0;
}
