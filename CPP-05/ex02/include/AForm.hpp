
#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		bool				signed_status;
		const int			required_sign_grade;
		const int			required_exec_grade;
	protected:
   		AForm();
   		virtual ~AForm();
   		AForm(const AForm& copyForm);
   		AForm& operator=(const Form& copyForm);
		AForm(int signgrade, int execgrade, std::string name);
		class GradeTooHighException;
		class GradeTooLowException;
		class AFormAlreadySignedException;
		virtual std::string getName() const = 0;
		virtual bool		getStatus() const = 0;
		virtual int			getSignedGrade() const = 0;
		virtual int			getExecGrade() const = 0;
		virtual void		BeSigned(const Bureaucrat& bureaucrat) = 0;
	public:
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

class AForm::AFormAlreadySignedException : public std::exception
{
	public:
		const char*	what() const throw();
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif

