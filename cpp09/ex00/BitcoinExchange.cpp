/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:56:08 by ncrivell          #+#    #+#             */
/*   Updated: 2026/01/21 16:06:16 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_csvDataMap = other._csvDataMap;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_csvDataMap = other._csvDataMap;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::parseLine(const std::string &date, const std::string &pipe, float value)
{
	parseDate(date);
	parsePipe(pipe);
	parseValue(value);

}

void	BitcoinExchange::putCsvIntoMap(const std::string &csv)
{
	std::ifstream csvFile(csv.c_str());
	if (!csvFile.is_open())
	{
		std::cerr << "Error : file data can't be open" << std::endl;
		return;
	}
	std::string	line;
	std::string	date;
	std::string	value;
	float		floatValue;
	std::getline(csvFile, line);
	while (std::getline(csvFile, line))
	{
		std::istringstream iss(line);
		std::getline(iss, date, ',');
		std::getline(iss, value);
		floatValue = std::atof(value.c_str());

		_csvDataMap[date] = floatValue;
	}
	csvFile.close();
}

float	BitcoinExchange::getBitcoinValue(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = _csvDataMap.lower_bound(date);
	if (it != _csvDataMap.end() && it->first == date)
		return it->second;
	else if (it != _csvDataMap.begin())
	{
		--it;
		return it->second;
	}
	throw std::runtime_error("Error : no data for this date");
}

void	BitcoinExchange::parseDate(const std::string &date)
{
	std::string	temp;
	int			year;
	int			month;
	int			day;


	if (date.length() != 10)
		throw std::runtime_error("Error : Date size must be exactly 10 characteres");
	if (date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Error : missing - between year, month and day");
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			throw std::runtime_error("Error : date must be digit number");
	}
	temp = date.substr(0, 4);
	year = std::atoi(temp.c_str());
	if (year < 2009 || year > 2022)
		throw std::runtime_error("Error : Year must be contained between 2009 and 2022");
	temp = date.substr(5, 2);
	month = std::atoi(temp.c_str());
	if (month < 1 || month > 12)
		throw std::runtime_error("Error : Month must be contained between 01 and 12");
	temp = date.substr(8, 2);
	day = std::atoi(temp.c_str());
	if (day < 1 || day > 31)
		throw std::runtime_error("Error : Day must be contained between 01 and 31");
	if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		throw std::runtime_error("Error : Day can't be a 31 with this month");
	if (day == 1 && (year == 2009) && (month == 1))
		throw std::runtime_error("Error : Data begin at 2009-01-02");
	if ((year == 2022 && month > 3) || (year == 2022 && month == 3 && day > 29))
		throw std::runtime_error("Error : Data stop at 2022-03-29");
	if (month == 2)
	{
		bool isBiss = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > 29 || (day == 29 && !isBiss))
			throw std::runtime_error("Error : Invalid day for February");
	}
}

void	BitcoinExchange::parsePipe(const std::string &pipe)
{
	if (pipe != "|")
		throw std::runtime_error("Error : there must have a | between date and value");
}

void	BitcoinExchange::parseValue(float value)
{
	if (value < 0 || value > 1000)
		throw std::runtime_error("Error : value must be contained between 0 and 1000");
}


