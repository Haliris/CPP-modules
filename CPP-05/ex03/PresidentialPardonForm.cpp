
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm(25, 5, "Presidential Pardon Form", "default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(25, 5, "Presidential Pardon Form", target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	(void)copy;
    return *this;
}
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getStatus() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())	
		throw GradeTooLowException();
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
