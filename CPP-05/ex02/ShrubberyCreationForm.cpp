#include "ShrubberyCreationForm.hpp"
#include <fstream>

const char*	ShrubberyCreationForm::NoSrcFileException::what() const throw()
{
	return "Could not open shrubbery source file!";
}

const char*	ShrubberyCreationForm::NoOutFileException::what() const throw()
{
	return "Could not open shrubbery out file!";
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(145, 137, "Shrubbery Creation Form", "default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(145, 137, "Shrubbery Creation Form", target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copyShrubberyCreationForm)
{
    *this = copyShrubberyCreationForm;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copyShrubberyCreationForm)
{
    if (this != &copyShrubberyCreationForm)
    {
    }
    return *this;
}


void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	std::ifstream	ShrubberySrc;
	std::ofstream	ShrubberyFile;
	std::string		file_name;
	std::string		line;

	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else
	{
		ShrubberySrc.open("ShrubberySrc.txt");	
		if (!ShrubberySrc)
			throw ShrubberyCreationForm::NoSrcFileException();
		file_name = this->getTarget() + "_shrubbery";	
		ShrubberyFile.open(file_name);
		if (!ShrubberyFile)
		{
			ShrubberySrc.close();
			throw ShrubberyCreationForm::NoOutFileException();
		}
		while (std::getline(ShrubberySrc, line))
			ShrubberyFile << line;
	}
	ShrubberySrc.close();
	ShrubberyFile.close();
}
