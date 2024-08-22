/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:00:00 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/22 14:09:50 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	Harl_2_0;

	std::cout << "------------" << std::endl;
	std::cout << "1 each test" << std::endl;
	std::cout << "------------" << std::endl;
	Harl_2_0.complain("DEBUG");
	Harl_2_0.complain("INFO");
	Harl_2_0.complain("WARNING");
	Harl_2_0.complain("ERROR");
	std::cout << "------------" << std::endl;
	std::cout << "4 DEBUG" << std::endl;
	std::cout << "------------" << std::endl;
	Harl_2_0.complain("DEBUG");
	Harl_2_0.complain("DEBUG");
	Harl_2_0.complain("DEBUG");
	Harl_2_0.complain("DEBUG");
	std::cout << "------------" << std::endl;
	std::cout << "4 INFO" << std::endl;
	std::cout << "------------" << std::endl;
	Harl_2_0.complain("INFO");
	Harl_2_0.complain("INFO");
	Harl_2_0.complain("INFO");
	Harl_2_0.complain("INFO");
	std::cout << "------------" << std::endl;
	std::cout << "4 WARNING" << std::endl;
	std::cout << "------------" << std::endl;
	Harl_2_0.complain("WARNING");
	Harl_2_0.complain("WARNING");
	Harl_2_0.complain("WARNING");
	Harl_2_0.complain("WARNING");
	std::cout << "------------" << std::endl;
	std::cout << "4 ERROR" << std::endl;
	std::cout << "------------" << std::endl;
	Harl_2_0.complain("ERROR");
	Harl_2_0.complain("ERROR");
	Harl_2_0.complain("ERROR");
	Harl_2_0.complain("ERROR");
	return (0);
}
