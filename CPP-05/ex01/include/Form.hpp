
#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				signed_status;
		const int			required_sign_grade;
		const int			required_exec_grade;
	public:
   		Form();
   		~Form();
   		Form(const Form& copyForm);
   		Form& operator=(const Form& copyForm);
		Form(int grade, std::string name);
		class GradeTooHighException;
		class GradeTooLowException;
		class FormAlreadySignedException;
		std::string getName() const;
		bool		getStatus() const;
		int			getSignedGrade() const;
		int			getExecGrade() const;
		void		BeSigned(const Bureaucrat& bureaucrat);
};

class Form::GradeTooHighException : public std::exception
{
	public:
		const char*	what() const throw();
};

class Form::GradeTooLowException : public std::exception
{
	public:
		const char*	what() const throw();
};

class Form::FormAlreadySignedException : public std::exception
{
	public:
		const char*	what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif

