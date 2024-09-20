#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(145, 137, "Shrubbery Creation Form")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copyShrubberyCreationForm)
{
    *this = copyShrubberyCreationForm;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copyShrubberyCreationForm)
{
    if (this != &copyShrubberyCreationForm)
    {
    }
    return *this;
}

