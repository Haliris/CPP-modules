/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:11 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/20 14:35:59 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "[GRADE][ERROR]: value too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "[GRADE][ERROR]: value too low.";
}

Bureaucrat::Bureaucrat() : name("default")
{
	grade = 42;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name)
{
	if (grade < 1)
	{
		std::cout << "bureaucrat name: ";
		std::cout << name << ", ";
		std::cout << "grade: " << grade << " ";
		throw Bureaucrat::GradeTooLowException();
	}
	if (grade > 150)
	{
		std::cout << "bureaucrat name: ";
		std::cout << name << ", ";
		std::cout << "grade: " << grade << " ";
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& copyBureaucrat) : name(copyBureaucrat.name)
{
    *this = copyBureaucrat;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copyBureaucrat)
{
    if (this != &copyBureaucrat)
		this->grade = copyBureaucrat.grade;
    return *this;
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::increaseGrade()
{
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade++;
}

void	Bureaucrat::signForm(int auth, std::string reason, std::string form_name) const
{
	if (auth == true)
		std::cout << this->getName() << " bureaucrat signed form " << form_name << std::endl;
	else
		std::cout << this->getName() << " bureaucrat could not sign form " << form_name << " reason: " << reason << std::endl;

}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << *this << " could not execute form: " << form;	
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}


