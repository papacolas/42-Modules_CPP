/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:13:11 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/17 15:33:37 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::~Point()
{}

Point::Point(const float f_num_a, const float f_num_b) : _x(Fixed(f_num_a)), _y(Fixed(f_num_b))
{}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{}

Point &Point::operator=(const Point &other)
{
	(void)other; //Pour eviter warning de parametre inutile
	return *this;
}

const Fixed &Point::get_X(void) const
{
	return this->_x;
}

const Fixed &Point::get_Y(void) const
{
	return this->_y;
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
	out << "Point(" << point.get_X() << ", " << point.get_Y() << ")";
	return out;
}
