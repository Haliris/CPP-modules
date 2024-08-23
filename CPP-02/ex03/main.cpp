/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:26:46 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 17:54:26 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point point(5, 5);
	Point bad_point(5, 15);
	Point corner_point(0, 0);
	Point edge_point(5, 0);

	if (bsp(a, b, c, point) == true)
		std::cout << "Success :)" << std::endl;
	else
		std::cout << "KO :(" << std::endl;

	if (bsp(a, b, c, bad_point) == false)
		std::cout << "Success :)" << std::endl;
	else
		std::cout << "KO :(" << std::endl;

	if (bsp(a, b, c, corner_point) == true)
		std::cout << "Success :)" << std::endl;
	else
		std::cout << "KO :(" << std::endl;

	if (bsp(a, b, c, edge_point) == true)
		std::cout << "Success :)" << std::endl;
	else
		std::cout << "KO :(" << std::endl;


	Point neg_a(-5, -5);
	Point neg_b(0, -5);
	Point neg_c(-2.5, 0);
	Point neg_point(-2.5, -2.5);
	Point bad_neg_point(-20, -2.5);


	if (bsp(neg_a, neg_b, neg_c, neg_point) == true)
		std::cout << "Success :)" << std::endl;
	else
		std::cout << "KO :(" << std::endl;

	if (bsp(neg_a, neg_b, neg_c, bad_neg_point) == false)
		std::cout << "Success :)" << std::endl;
	else
		std::cout << "KO :(" << std::endl;

	return 0;
}

