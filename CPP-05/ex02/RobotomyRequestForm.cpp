
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(72, 45, "Robotomy Request Form", "default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(72, 45, "Robotomy Request Form", target)
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor, std::string target)
{
	if (executor.getGrade() < this->getExecGrade())	
	{
		throw AForm::GradeTooLowException();
	}
	else
		std::cout << target << " has been pardonned by Zaphod Beelblebrox." << std::endl;
}
 
