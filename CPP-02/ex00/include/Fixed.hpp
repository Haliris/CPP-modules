/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:34:05 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/22 18:40:19 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& copyFixed);
		Fixed& operator=(const Fixed& copyFixed){
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &copyFixed) {
				value = copyFixed.value;
			}
			return *this;
		}
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
