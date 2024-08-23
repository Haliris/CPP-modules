/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:26:46 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 17:02:31 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point point(10, 15);

	if (bsp(a, b, c, point) == true)
		std::cout << "Success :)" << std::endl;
	else
		std::cout << "KO :(" << std::endl;

	Point A(1000000, 1000000);
	Point B(2000000, 1000000);
	Point C(1500000, 2000000);
	Point large_point(2500000, 1500000);

	if (bsp(A, B, C, large_point) == false)
		std::cout << "Success :)" << std::endl;
	else
		std::cout << "KO :(" << std::endl;


	return 0;
}

