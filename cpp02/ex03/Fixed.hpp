/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:13:02 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/19 17:25:47 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
	private:
		int	_value;
		static const int _store_fractional;

	public:
		//-----Constructeurs-----//

		//Constructeur par defaut
		Fixed();
		//Constructeur depuis un int
		Fixed(const int num);
		//Constructeur depuis un floating
		Fixed(const float f_num);
		//Constructeur de copie
		Fixed(const Fixed &other);
		//Copy assignment operator overload
		Fixed &operator=(const Fixed &other);
		//Destructeur
		~Fixed();

		//-----Fonctions membres-----//

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed 	operator+(const Fixed &other) const;
		Fixed 	operator-(const Fixed &other) const;
		Fixed 	operator*(const Fixed &other) const;
		Fixed 	operator/(const Fixed &other) const;

		Fixed 	&operator++();
		Fixed 	operator++(int);
		Fixed 	&operator--();
		Fixed 	operator--(int);

		static	Fixed	&min(Fixed &a, Fixed &b);
		static	const Fixed	&min(const Fixed &a, const Fixed &b);
		static	Fixed	&max(Fixed &a, Fixed &b);
		static	const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif
