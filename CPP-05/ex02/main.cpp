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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	default_bureaucrat;
		Bureaucrat	good_boss(1, "boss");
		Bureaucrat	good_manager(30, "manager");
		Bureaucrat	good_intern(150, "intern");
		std::cout << default_bureaucrat.getGrade() << std::endl;
		std::cout << good_boss.getGrade() << std::endl;
		std::cout << good_manager.getGrade() << std::endl;
		std::cout << good_intern.getGrade() << std::endl;
		std::cout << default_bureaucrat << std::endl;
		std::cout << good_boss << std::endl;
		std::cout << good_manager << std::endl;
		std::cout << good_intern << std::endl;
	
		ShrubberyCreationForm	shrub_form("good_manager");
		RobotomyRequestForm		robo_form("good_intern");
		PresidentialPardonForm	pres_form("good_boss");

		good_boss.executeForm(robo_form);
		robo_form.BeSigned(good_boss);
//		robo_form.BeSigned(good_boss);
		good_boss.executeForm(robo_form);
//		pres_form.BeSigned(good_manager);
		pres_form.BeSigned(good_boss);
		good_manager.executeForm(pres_form);
		good_boss.executeForm(pres_form);
		good_intern.executeForm(shrub_form);
		shrub_form.BeSigned(good_manager);
		good_manager.executeForm(shrub_form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}

