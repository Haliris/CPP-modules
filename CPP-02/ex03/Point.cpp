/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:48:00 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 17:04:33 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(const Point& pointCpy)
{
	*this = pointCpy;
}

Point::~Point()
{
}

Fixed	Point::getX()
{
	return this->x;
}

Fixed Point::getY()
{
	return this->y;
}

Point	&Point::operator=(const Point &pointCpy)
{
	if (this != &pointCpy)
	{
		this->x = pointCpy.x;
		this->y = pointCpy.y;
	}
	return *this;
}
