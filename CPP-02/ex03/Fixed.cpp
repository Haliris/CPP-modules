/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:41:09 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 16:57:01 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const int int_nb)
{
	value = int_nb << bits;
}

Fixed::Fixed(const float float_nb)
{
	value = roundf(float_nb * (1 << bits));
}

Fixed::Fixed(const Fixed& copyFixed)
{
	*this = copyFixed;
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(const Fixed& copyFixed)
{
	if (this != &copyFixed) {
		value = copyFixed.getRawBits();
	}
	return *this;
}

Fixed	Fixed::operator+(const Fixed& number)
{
	Fixed	newValue;

	newValue.value = this->value + number.getRawBits();
	return newValue;
}

Fixed	Fixed::operator-(const Fixed& number)
{
	Fixed	newValue;

	newValue.value = this->value - number.getRawBits();
	return newValue;
}

Fixed	Fixed::operator*(const Fixed& number)
{
	Fixed	newValue;

	newValue.value = (this->value * number.getRawBits()) / (1 << bits);
	return newValue;
}

Fixed	Fixed::operator/(const Fixed& number)
{
	Fixed	newValue;

	newValue.value = ((this->value * (1 << bits)) / number.getRawBits());
	return newValue;
}

Fixed&	Fixed::operator++()
{
	value++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	value++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	value--;
	return (temp);
}

bool	Fixed::operator==(const Fixed& comparedNb)
{
	return (value == comparedNb.getRawBits());
}

bool	Fixed::operator!=(const Fixed& comparedNb)
{
	return (value != comparedNb.getRawBits());
}

bool	Fixed::operator<(const Fixed& comparedNb)
{
	return (value < comparedNb.getRawBits());
}

bool	Fixed::operator>(const Fixed& comparedNb)
{
	return (value > comparedNb.getRawBits());
}

bool	Fixed::operator<=(const Fixed& comparedNb)
{
	return (value <= comparedNb.getRawBits());
}

bool	Fixed::operator>=(const Fixed& comparedNb)
{
	return (value >= comparedNb.getRawBits());
}


Fixed	&Fixed::max(Fixed &ref1, Fixed &ref2)
{
	return (ref1.getRawBits() > ref2.getRawBits() ? ref1 : ref2);
}

Fixed	&Fixed::min(Fixed &ref1, Fixed &ref2)
{
	return (ref1.getRawBits() > ref2.getRawBits() ? ref2 : ref1);
}

const Fixed	&Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	return (ref1.getRawBits() > ref2.getRawBits() ? ref2 : ref1);
}

const Fixed	&Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	return (ref1.getRawBits() > ref2.getRawBits() ? ref1 : ref2);
}

int		Fixed::getRawBits(void) const
{
	return value;
}

void	Fixed::setRawBits(int const raw)
{
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
