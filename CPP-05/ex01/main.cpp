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
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	default_bureaucrat;
		Bureaucrat	good_boss(1, "boss");
		Bureaucrat	good_manager(70, "manager");
		Bureaucrat	good_intern(150, "intern");
//		Form		bad_form(-1, "bad_form");
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
		Form	default_form;
		Form	boss_form(2, "boss_form");
		Form	manager_form(71, "manager_form");
		Bureaucrat	boss(1, "boss");
		Bureaucrat	manager(70, "manager");
		Bureaucrat	intern(150, "intern");
		
//		boss_form.BeSigned(intern);
		std::cout << default_form;
		std::cout << boss_form;
		std::cout << manager_form;
		boss_form.BeSigned(boss);
//		boss_form.BeSigned(boss);
//		manager_form.BeSigned(intern);
		manager_form.BeSigned(manager);
//		manager_form.BeSigned(manager);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
