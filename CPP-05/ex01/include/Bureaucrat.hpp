/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:35:16 by jteissie          #+#    #+#             */
/*   Updated: 2024/09/20 14:35:17 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copyBureaucrat);
		Bureaucrat& operator=(const Bureaucrat& copyBureaucrat);
		Bureaucrat(int grade, std::string name);
		std::string	getName() const;
		int			getGrade() const;
		void		signForm(int auth, std::string reason, std::string form_name) const;
		void		increaseGrade();
		void		decreaseGrade();
		class		GradeTooHighException;
		class		GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char*	what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char*	what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif

