/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:25:52 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 17:07:25 by jteissie         ###   ########.fr       */
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

	return Fixed((a_x * (b_y - c_y) + b_x * (c_y - a_y) + c_x * (a_y - b_y)).toFloat() / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	main_area;
	Fixed	area_1;
	Fixed	area_2;
	Fixed	area_3;

	main_area = calculateArea(a, b, c);
	area_1 = calculateArea(point, b, c);
	area_2 = calculateArea(a, point, c);
	area_3 = calculateArea(a, b, point);
	if (area_1 + area_2 + area_3 == main_area)
		return (true);
	return (false);
}
