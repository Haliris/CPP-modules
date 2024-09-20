
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& copyPresidentialPardonForm);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copyPresidentialPardonForm);
		PresidentialPardonForm(std::string target);
};

#endif

