/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:55:58 by ncrivell          #+#    #+#             */
/*   Updated: 2026/01/21 13:18:09 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : Must have 2 arguments" << std::endl;
		return 1;
	}

	std::string firstLine;
	std::ifstream fileTxt(argv[1]);
	if (!fileTxt.is_open())
	{
		std::cerr << "Error : file can't be open" << std::endl;
		return 1;
	}

	std::string key2 ("date | value");
	std::getline(fileTxt, firstLine);
	if (firstLine != key2)
	{
		std::cerr << "Error : first line has not the good format" << std::endl;
		return 1;
	}

	BitcoinExchange	trade;
	trade.putCsvIntoMap("data.csv");

	std::string line;
	while (std::getline(fileTxt, line))
	{
		std::string	date;
		std::string	pipe;
		float		numberOfBitcoin;

		std::istringstream iss(line);
		if (!(iss >> date >> pipe >> numberOfBitcoin))
		{
			std::cout << "Error : bad input => " << line << std::endl;
			continue;
		}

		try {
			trade.parseLine(date, pipe, numberOfBitcoin);
			float	bitcoinValue = trade.getBitcoinValue(date);
			std::cout << date << " => " << numberOfBitcoin << " = " << bitcoinValue * numberOfBitcoin << std::endl;
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}

	fileTxt.close();

	return 0;
}
