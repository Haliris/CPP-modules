
#include "Form.hpp"

Form::Form() : name("form"), required_sign_grade(100), required_exec_grade(42)
{
	is_signed = false;
}

Form::~Form()
{
}

Form::Form(const Form& copyForm) : Form()
{
    *this = copyForm;
}

Form& Form::operator=(const Form& copyForm)
{
    if (this != &copyForm)
    {
		this->is_signed = copyForm.is_signed;
    }
    return *this;
}

std::string	Form::getName() const
{
	return this->name;
}
