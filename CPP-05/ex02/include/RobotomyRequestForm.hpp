
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copyRobotomyRequestForm);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copyRobotomyRequestForm);
		RobotomyRequestForm(std::string target);
		void	execute(Bureaucrat const & executor);
};

#endif

