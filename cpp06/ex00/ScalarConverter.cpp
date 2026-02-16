/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:35:16 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:12 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>

static void convertFromChar(const std::string &literal);
static void convertFromInt(const std::string &literal);
static void convertFromFloat(const std::string &literal);
static void convertFromDouble(const std::string &literal);
static void printScalarTypes(char c, int i, double d, float f);

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter(void)
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}


bool	ScalarConverter::isChar(const std::string &str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool	ScalarConverter::isInt(const std::string &str)
{
	int	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i = 1;

	if (i == 1 && str.length() < 2)
		return false;

	while (str[i])
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
		i++;
	}
	return true;
}

bool	ScalarConverter::isFloat(const std::string &str)
{
	size_t	i = 0;

	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
		return true;

	if (str[0] == '+' || str[0] == '-')
		i = 1;

	if (str.length() < 4)
		return false;

	size_t temp = i;
	int	point = 0;

	while (temp < str.length() - 1)
	{
		if (str[temp] == '.' && point == 0)
			point = 1;
		else if (str[temp] == '.' && point == 1)
			return false;
		else if (!std::isdigit(static_cast<unsigned char>(str[temp])))
			return false;
		temp++;
	}
	if (point == 0)
		return false;

	if (str[str.length() - 1] != 'f')
		return false;

	return true;
}

bool	ScalarConverter::isDouble(const std::string &str)
{	int	i = 0;

	if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
		return true;

	if (str[0] == '+' || str[0] == '-')
		i = 1;

	if (str.length() < 3)
		return false;

	int temp = i;
	int	point = 0;

	while (str[temp])
	{
		if (str[temp] == '.' && point == 0)
			point = 1;
		else if (str[temp] == '.' && point == 1)
			return false;
		else if (!std::isdigit(static_cast<unsigned char>(str[temp])))
			return false;
		temp++;
	}
	if (point == 0)
		return false;

	return true;
}


void	convertFromChar(const std::string &literal)
{
	char	c;
	int		i;
	double	d;
	float	f;

	c = literal[1];
	i = static_cast<int>(c);
	d = static_cast<double>(i);
	f = static_cast<float>(i);

	printScalarTypes(c, i, d, f);
}

void	convertFromInt(const std::string &literal)
{
	char	c;
	int		i;
	double	d;
	float	f;
	long	temp;

	std::stringstream ss(literal);
	if (!(ss >> temp) || !ss.eof())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	i = static_cast<int>(temp);
	d = static_cast<double>(temp);
	f = static_cast<float>(temp);
	c = static_cast<char>(temp);
	printScalarTypes(c, i, d, f);
}

void	convertFromDouble(const std::string &literal)
{
	char	c;
	int		i;
	double	d = 0.0;
	float	f;

	if (literal == "nan")
		d = nan("");
	else if (literal == "+inf" || literal == "inf")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf")
		d = -std::numeric_limits<double>::infinity();
	else
	{
		std::stringstream ss(literal);
		if (!(ss >> d) || !ss.eof())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	if (std::isnan(d) || std::isinf(d))
	{
		f = static_cast<float>(d);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (std::isinf(d))
		{
			std::cout << "float: " << (literal == "+inf" ? "+" : "");
			std::cout << f << "f" << std::endl;
			std::cout << "double: " << (literal == "+inf" ? "+" : "");
			std::cout << d << std::endl;
			return;
		}
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return;
	}
	else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
	{
		f = static_cast<float>(d);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	c = static_cast<char>(d);
	printScalarTypes(c, i, d, f);
}

void	convertFromFloat(const std::string &literal)
{	char	c;
	int		i;
	double	d = 0.0;
	float	f = 0.0;

	if (literal == "nanf")
		f = nan("");
	else if (literal == "+inff" || literal == "inff")
		f = std::numeric_limits<float>::infinity();
	else if (literal == "-inff")
		f = -std::numeric_limits<float>::infinity();
	else
	{
		std::stringstream ss(literal);
		if (!(ss >> f))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	if (std::isnan(f) || std::isinf(f))
	{
		d = static_cast<double>(f);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (std::isinf(d))
		{
			std::cout << "float: " << (literal == "+inff" ? "+" : "");
			std::cout << f << "f" << std::endl;
			std::cout << "double: " << (literal == "+inff" ? "+" : "");
			std::cout << d << std::endl;
			return;
		}
		else
		{
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		}
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return;
	}
	else if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
	{
		d = static_cast<double>(f);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	c = static_cast<char>(f);
	printScalarTypes(c, i, d, f);

}


void	ScalarConverter::convert(std::string literal)
{
	if (isChar(literal))
		convertFromChar(literal);
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void	printScalarTypes(char c, int i, double d, float f)
{
	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
