
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# define MAX_GRADE 1;
# define MIN_GRADE 150;

class Bureaucrat
{
private:
	const std::string	name;
	unsigned int		grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& copyBureaucrat);
    Bureaucrat& operator=(const Bureaucrat& copyBureaucrat);
	Bureaucrat(int grade);
	std::string	getName() const;
	int			getGrade() const;
	int		GradeTooHighException();
	int		GradeTooLowException();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif

