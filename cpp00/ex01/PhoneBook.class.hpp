/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:44:31 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/03 15:22:09 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <iostream>
#include "Contact.class.hpp"

class PhoneBook
{
	private:
		Contact	_phonebook[8];
		int		_index;
		int		_count;

		std::string	getInput(std::string prompt);
		std::string	formatLength(std::string field);
		void		displayPhonebook();

	public:
		PhoneBook(void);
		~PhoneBook();

		void	addContact();
		void	searchContact();
};





#endif
