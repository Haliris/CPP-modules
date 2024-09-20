
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	int	roll;

	if (executor.getGrade() < this->getExecGrade())	
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << "* Drilling noise *" << std::endl;
		roll = rand() % 100;
		if (roll >= 50)
			std::cout << this->getTarget() << " Has been robotomized succesfully." << std::endl;
		else
			std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
	}
}
 
