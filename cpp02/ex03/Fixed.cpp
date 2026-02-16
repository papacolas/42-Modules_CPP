/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:12:59 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/19 17:38:52 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_store_fractional = 8;

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return *this;
}

Fixed::Fixed(const int num) : _value(num << _store_fractional)
{
	// std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float f_num) : _value(roundf(f_num * (1 << _store_fractional)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_value / (1 << _store_fractional);
}

int		Fixed::toInt(void) const
{
	return _value >> _store_fractional;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}


bool	Fixed::operator>(const Fixed &other) const
{
	return _value > other._value;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return _value < other._value;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return _value >= other._value;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return _value <= other._value;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return _value == other._value;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return _value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result._value = (_value * other._value) >> _store_fractional;
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result._value = (_value << _store_fractional) / other._value;
	return result;
}

Fixed &Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_value++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

