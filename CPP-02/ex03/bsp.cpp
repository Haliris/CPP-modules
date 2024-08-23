/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:25:52 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 17:47:42 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	calculateArea(Point a, Point b, Point c)
{
	Fixed a_x = a.getX();
	Fixed a_y = a.getY();
	Fixed b_x = b.getX();
	Fixed b_y = b.getY();
	Fixed c_x = c.getX();
	Fixed c_y = c.getY();

	Fixed area = ((a_x * (b_y - c_y) + b_x * (c_y - a_y) + c_x * (a_y - b_y)).toFloat() / 2);

	return Fixed(std::abs(area.toFloat()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	mainArea;
	Fixed	area_1;
	Fixed	area_2;
	Fixed	area_3;

	mainArea = calculateArea(a, b, c);
	area_1 = calculateArea(point, b, c);
	area_2 = calculateArea(a, point, c);
	area_3 = calculateArea(a, b, point);

	Fixed	areaSum = area_1 + area_2 + area_3;
	// Fixed	epsilon(0.0f);

	if (std::abs((mainArea).toFloat()) == (areaSum).toFloat() /* <epsilon.toFloat() */)
		return (true);
	return (false);
}
