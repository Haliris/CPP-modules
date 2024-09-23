
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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	(void)copy;
    return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	roll;

	if (this->getStatus() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() < this->getExecGrade())	
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		srand(time(0));
		std::cout << "* Drilling noise *" << std::endl;
		roll = rand() % 100;
		if (roll >= 50)
			std::cout << this->getTarget() << " Has been robotomized succesfully." << std::endl;
		else
			std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
	}
}
 
