/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:35:13 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/04 17:24:22 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP
#include <string>

class ScalarConverter
{
	private:
	
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &other);

		static	bool	isChar(const std::string &str);
		static	bool	isInt(const std::string &str);
		static	bool	isDouble(const std::string &str);
		static	bool	isFloat(const std::string &str);

	public:

		static void convert(std::string literal);
};

#endif
