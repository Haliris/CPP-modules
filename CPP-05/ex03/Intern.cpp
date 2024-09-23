
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const char*	Intern::NoFormTypeException::what() const throw()
{
	return "[INTERN][ERROR] no such form type";
}

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& copyIntern)
{
    *this = copyIntern;
}

Intern& Intern::operator=(const Intern& copyIntern)
{
	(void)copyIntern;
    return *this;
}

AForm*	Intern::makeForm(std::string type, std::string target)
{
	AForm	*Form;
	int	search = -1;
	std::string levels[3] = {"presidential", "shrubbery", "robotomy"};
	for (int i = 0; i < type.length(); i++)
	{
		if (type[i] >= 'A' && type[i] <= 'Z')
			type[i] -= 32;
	}
	for (int i = 0; i < 3; i++)	
	{
		if (levels[i] == type)
			search = i;
	}
	if (search == -1)
		throw NoFormTypeException();
	switch (search)
	{
		case PRESIDENTIAL:
			Form = new PresidentialPardonForm(target);
			break ;
		case SHRUBBERY:
			Form = new ShrubberyCreationForm(target);
			break ;
		case ROBOTOMY:
			Form = new RobotomyRequestForm(target);
			break ;
	}
	std::cout << "Intern creates " << Form << std::endl;
	return Form;
}
