#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	name = "bureaucrat";
	grade = MIN_GRADE;
}

Bureaucrat::Bureaucrat(int grade)
{
	if (grade < MAX_GRADE)	
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else
	{
		name = "bureaucrat";
		this->grade = grade;
	}
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
    {
		this->name = copyBureaucrat.name;
		this->grade = copyBureaucrat.grade;
    }
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

int		Bureaucrat::GradeTooHighException()
{
	std::cout << "Bureaucrat too high!" << std::endl;
	return 1;
}

int		Bureaucrat::GradeTooLowException()
{
	std::cout << "Bureacrat grade too low!" << std::endl;
	return 1;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
} 
