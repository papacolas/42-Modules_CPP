/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:13:14 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/19 17:26:20 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(const float f_num_a, const float f_num_b);
		Point(const Point &other);
		~Point();
		Point &operator=(const Point &other);
		const Fixed &get_X(void) const;
		const Fixed &get_Y(void) const;

};
std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
