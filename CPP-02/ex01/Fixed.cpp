/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:41:09 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/22 19:24:07 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_nb)
{
	std::cout << "Integer constructor called" << std::endl;
	value = int_nb << bits;
}

Fixed::Fixed(const float float_nb)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(float_nb * (1 << bits));
}

Fixed::Fixed(const Fixed& copyFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyFixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{

	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

int		Fixed::toInt(void) const
{
	return (roundf(this->value / (float)(1 << bits)));
}

float	Fixed::toFloat(void) const
{
	return (this->value / (float)(1 << bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
