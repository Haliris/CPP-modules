/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:26:46 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 15:38:04 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );

// 	a = Fixed( 1234.4321f );

// 	return 0;
// }


// int	main()
// {
// 	Fixed a(10);
// 	Fixed b(2);
// 	Fixed A(100);
// 	Fixed B(100);

// 	if (A == B)
// 		std::cout << "A = " << A << " is equal to B =" << B << std::endl;
// 	A++;
// 	if (A != B)
// 		std::cout << "A = " << A << " is different than B =" << B << std::endl;
// 	A--;
// 	std::cout << "A = " << A << std::endl;
// 	if (A <= B)
// 		std::cout << "A = " << A << " is inferior or equal to B =" << B << std::endl;
// 	A--;
// 	if (A <= B)
// 		std::cout << "A = " << A << " is inferior or equal to B =" << B << std::endl;
// 	A++;
// 	B++;
// 	B--;
// 	if (A >= B)
// 		std::cout << "A = " << A << " is superior or equal to B =" << B << std::endl;
// 	A++;
// 	if (A >= B)
// 		std::cout << "A = " << A << " is superior or equal to B =" << B << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	Fixed c = a + b;
// 	std::cout << "a + b = " << c << std::endl;
// 	if (c > a)
// 		std::cout << "c = " << c << " is inferior to a = " << a << std::endl;
// 	if (c > b)
// 		std::cout << "c = " << c << " is inferior to a = " << a << std::endl;
// 	Fixed d = a - b;
// 	std::cout << "a - b = " << d << std::endl;
// 	Fixed e = a * b;
// 	std::cout << "a * b = " << e << std::endl;
// 	Fixed f = a / b;
// 	std::cout << "a / b = " << f << std::endl;

// 	return 0;
// }


int	main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
