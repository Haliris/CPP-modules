
#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			required_sign_grade;
		const int			required_exec_grade;
	public:
   		Form();
   		~Form();
   		Form(const Form& copyForm);
   		Form& operator=(const Form& copyForm);
		class GradeTooHighException;
		class GradeTooLowException;
		std::string	getName() const;
		void	BeSigned(const Bureaucrat bureaucrat);
};

class GradeTooHighException : public std::exception
{
	public:
		const char*	what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
		const char*	what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Form& form);
#endif

