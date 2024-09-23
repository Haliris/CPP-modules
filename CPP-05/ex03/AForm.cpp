
#include "AForm.hpp"

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "[GRADE][ERROR]: Grade too low.";
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "[GRADE][ERROR]: Grade too high.";
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return "[FORM][ERROR]: Already signed.";
}

const char*	AForm::NotSignedException::what() const throw()
{
	return "[FORM][ERROR]: Form is not signed.";
}

AForm::AForm() : name("form"), target("default"), required_sign_grade(100), required_exec_grade(42)
{
	signed_status = false;
}

AForm::AForm(int signgrade, int execgrade, std::string name, std::string target) : name(name), target(target), required_sign_grade(signgrade), required_exec_grade(execgrade)
{
	signed_status = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& copyAForm) : name(copyAForm.getName()), required_sign_grade(copyAForm.getSignedGrade()), required_exec_grade(copyAForm.getExecGrade())
{
    *this = copyAForm;
}

AForm& AForm::operator=(const AForm& copyAForm)
{
    if (this != &copyAForm)
    {
		this->signed_status = copyAForm.signed_status;
    }
    return *this;
}

std::string	AForm::getName() const
{
	return this->name;
}

bool	AForm::getStatus() const
{
	return this->signed_status;
}

int	AForm::getSignedGrade() const
{
	return this->required_sign_grade;
}

int	AForm::getExecGrade() const
{
	return this->required_exec_grade;
}

std::string	AForm::getTarget() const
{
	return this->target;
}

void	AForm::BeSigned(const Bureaucrat& bureaucrat)
{
	if (signed_status == true)
	{
		bureaucrat.signForm(false, "AForm already signed", this->getName());
		throw AForm::AlreadySignedException();
	}
	if (bureaucrat.getGrade() < required_sign_grade)
	{
		signed_status = true;
		bureaucrat.signForm(true, "", this->getName());
	}
	else
	{
		bureaucrat.signForm(false, "Grade too low", this->getName());
		throw AForm::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	std::cout << form.getName() << ", form signed status " << form.getStatus();
	std::cout << ", required grade to sign " << form.getSignedGrade() << ", required grade to execute " << form.getExecGrade() << std::endl;
	return os;
}
