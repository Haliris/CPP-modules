
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(72, 45, "Robotomy Request Form")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copyRobotomyRequestForm)
{
    *this = copyRobotomyRequestForm;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copyRobotomyRequestForm)
{
    if (this != &copyRobotomyRequestForm)
    {
    }
    return *this;
}

