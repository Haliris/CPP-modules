
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
};

#endif

