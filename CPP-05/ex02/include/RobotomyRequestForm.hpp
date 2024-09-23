
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

class RobotomyRequestForm : public AForm
{
	private:
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		RobotomyRequestForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
};

#endif

