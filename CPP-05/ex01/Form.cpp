
#include "Form.hpp"


const char*	Form::GradeTooLowException::what() const throw()
{

}

Form::Form() : name("form"), required_sign_grade(100), required_exec_grade(42)
{
	signed_status = false;
}

Form::~Form()
{
}

Form::Form(const Form& copyForm) : Form()
{
    *this = copyForm;
}

Form& Form::operator=(const Form& copyForm)
{
    if (this != &copyForm)
    {
		this->signed_status = copyForm.signed_status;
    }
    return *this;
}

std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getStatus() const
{
	return this->signed_status;
}

int	Form::getSignedGrade() const
{
	return this->required_sign_grade;
}

int	Form::getExecGrade() const
{
	return this->required_exec_grade;
}

void	Form::BeSigned(const Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() < required_sign_grade)
	{
		signed_status = true;
		bureaucrat.signForm(this, true, "");
	}
	else
	{
		bureaucrat.signForm(this, false, "Grade too low");
		throw Form::GradeTooLowException()
	}
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{

	std::cout << form.getName() << ", form signed status " << form.getStatus();
	std::cout << ", required grade to sign " << form.getSignedGrade() << ", required grade to execute " << form.getExecGrade() << std::endl;
	return os;
}
