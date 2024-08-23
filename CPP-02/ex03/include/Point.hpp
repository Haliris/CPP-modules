/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:42:29 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 17:05:32 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"
# include <cmath>

class	Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& pointCpy);
		Point	&operator=(const Point &pointCpy);
		~Point();
		Fixed	getX();
		Fixed	getY();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
