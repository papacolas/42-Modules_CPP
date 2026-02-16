/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:56:02 by ncrivell          #+#    #+#             */
/*   Updated: 2026/01/21 12:53:49 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_csvDataMap;
		void							parseDate(const std::string &date);
		void							parsePipe(const std::string &pipe);
		void							parseValue(float value);

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void	parseLine(const std::string &date, const std::string &pipe, float value);
		void	putCsvIntoMap(const std::string &csv);
		float	getBitcoinValue(const std::string &date) const;
};

#endif
