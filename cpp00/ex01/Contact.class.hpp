/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:52:09 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/03 11:40:01 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
#include <iostream>

class Contact {
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkest_secret;

	public:
		Contact(void);
		~Contact(void);

		std::string getFirstName(void) const;
		void		setFirstName(std::string first);
		std::string getLastName(void) const;
		void		setLastName(std::string last);
		std::string getNickName(void) const;
		void		setNickName(std::string nick);
		std::string getPhoneNumber(void) const;
		void		setPhoneNumber(std::string phone);
		std::string getDarkestSecret(void) const;
		void		setDarkestSecret(std::string secret);
};



#endif
