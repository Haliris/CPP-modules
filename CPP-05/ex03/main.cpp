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
#include "Intern.hpp"
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
		Intern		dude;
		AForm		*form = NULL;
		AForm		*form2 = NULL;
		form = dude.makeForm("Robotomy", "good_intern");	
//		form = dude.makeForm("nothing", "good_intern");	
		form2 = dude.makeForm("Presidential request", "good_intern");	
		form->BeSigned(good_manager);
		form2->BeSigned(good_boss);
		good_manager.executeForm(*form);
		good_boss.executeForm(*form2);
		delete form;
		delete form2;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}

