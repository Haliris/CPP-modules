
#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
#include <string>

class AForm
{
	private:
		const std::string	name;
		const std::string	target;
		bool				signed_status;
		const int			required_sign_grade;
		const int			required_exec_grade;
	protected:
	public:
   		AForm();
   		virtual ~AForm();
   		AForm(const AForm& copyForm);
   		AForm& operator=(const AForm& copyForm);
		AForm(int signgrade, int execgrade, std::string name, std::string target);
		class GradeTooHighException;
		class GradeTooLowException;
		class AlreadySignedException;
		class NotSignedException;
		std::string getName() const;
		bool		getStatus() const;
		int			getSignedGrade() const;
		int			getExecGrade() const;
		std::string	getTarget() const;
		void		BeSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) = 0;

};

class AForm::GradeTooHighException : public std::exception
{
	public:
		const char*	what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		const char*	what() const throw();
};

class AForm::AlreadySignedException : public std::exception
{
	public:
		const char*	what() const throw();
};

class AForm::NotSignedException : public std::exception
{
	public:
		const char*	what() const throw();
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif

