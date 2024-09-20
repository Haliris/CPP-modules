
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copyShrubberyCreationForm);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copyShrubberyCreationForm);
		ShrubberyCreationForm(std::string target);
		void	execute(Bureaucrat const & executor);
		class	NoSrcFileException;
		class	NoOutFileException;
};

class ShrubberyCreationForm::NoSrcFileException : public std::exception
{
	public:
		const char*	what() const throw();
};

class ShrubberyCreationForm::NoOutFileException : public std::exception
{
	public:
		const char*	what() const throw();
};

#endif

