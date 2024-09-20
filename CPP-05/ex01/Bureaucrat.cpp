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
#include <string>


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

Bureaucrat::Bureaucrat(const Bureaucrat& copyBureaucrat)
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

void	Bureaucrat::signForm(const Form form, int auth, std::string reason)
{
	if (auth == true)
		std::cout << name << " bureaucrat signed form " << form.getName() << std::endl;
	else
		std::cout << name << " bureaucrat could not sign form " << form.getName() << " because " << reason << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}
