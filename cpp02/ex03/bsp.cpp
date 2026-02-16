/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:12:55 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/17 15:31:11 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static Fixed area(Point const &aa, Point const &bb ,Point const &cc)
{
	Fixed result;

	result = aa.get_X() * (bb.get_Y() - cc.get_Y()) +
			 bb.get_X() * (cc.get_Y() - aa.get_Y()) +
			 cc.get_X() * (aa.get_Y() - bb.get_Y());
	result = result / Fixed(2);
	if (result < Fixed(0))
		result = result * Fixed(-1);
	return result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	a1;
	Fixed	a2;
	Fixed	a3;
	Fixed	abc;

	abc = area(a, b, c);
	a1 = area(point, a, b);
	a2 = area(point, b, c);
	a3 = area(point, c, a);

	if (a1 == Fixed(0) || a2 == Fixed(0) || a3 == Fixed(0))
		return false;
	return ((a1 + a2 + a3) == abc);
}

