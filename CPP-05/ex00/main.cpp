/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:14 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/20 14:35:21 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	default_bureaucrat;
		Bureaucrat	good_boss(1, "boss");
		Bureaucrat	good_manager(70, "manager");
		Bureaucrat	good_intern(150, "intern");
		std::cout << default_bureaucrat.getGrade() << std::endl;
		std::cout << good_boss.getGrade() << std::endl;
		std::cout << good_manager.getGrade() << std::endl;
		std::cout << good_intern.getGrade() << std::endl;
		std::cout << default_bureaucrat;
		std::cout << good_boss;
		std::cout << good_manager;
		std::cout << good_intern;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	
	try
	{
		Bureaucrat	bad_boss(-1, "bad boss");	
		Bureaucrat	bad_intern(151, "bad intern");
		std::cout << bad_boss;
		std::cout << bad_intern;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
