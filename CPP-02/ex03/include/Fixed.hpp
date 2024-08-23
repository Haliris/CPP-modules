/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:34:05 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 15:37:21 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const int int_nb);
		Fixed(const float float_nb);
		Fixed(const Fixed& copyFixed);
		Fixed&	operator=(const Fixed& copyFixed);
		bool	operator==(const Fixed& comparedNb);
		bool	operator!=(const Fixed& comparedNb);
		bool	operator<(const Fixed& comparedNb);
		bool	operator>(const Fixed& comparedNb);
		bool	operator<=(const Fixed& comparedNb);
		bool	operator>=(const Fixed& comparedNb);
		Fixed	operator+(const Fixed& number);
		Fixed	operator-(const Fixed& number);
		Fixed	operator*(const Fixed& number);
		Fixed	operator/(const Fixed& number);
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed&	min(Fixed &ref1, Fixed &ref2);
		static Fixed&	max(Fixed &ref1, Fixed &ref2);
		static const Fixed&	min(const Fixed& ref1, const Fixed& ref2);
		static const Fixed&	max(const Fixed& ref1, const Fixed& ref2);
		~Fixed();
		int		getRawBits(void)	const;
		void	setRawBits(int const raw);
		int		toInt(void)			const;
		float	toFloat(void)		const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
