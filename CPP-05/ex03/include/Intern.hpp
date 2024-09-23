
#ifndef INTERN_HPP
# define INTERN_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"

typedef enum levels
{
	PRESIDENTIAL = 0,
	SHRUBBERY = 1,
	ROBOTOMY = 2
}	e_levels;

class Intern
{
	private:
	public:
		Intern();
		~Intern();
		Intern(const Intern& copyIntern);
		Intern& operator=(const Intern& copyIntern);
		AForm*	makeForm(std::string type, std::string target);
		class  NoFormTypeException;
};

class Intern::NoFormTypeException:  public std::exception
{
	public:
		const char*	what() const throw();
};

#endif

