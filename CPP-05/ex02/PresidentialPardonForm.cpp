
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

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copyPresidentialPardonForm)
{
    *this = copyPresidentialPardonForm;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copyPresidentialPardonForm)
{
    if (this != &copyPresidentialPardonForm)
    {
    }
    return *this;
}

