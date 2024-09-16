#include "AMateria.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource default destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copyMateriaSource)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource& copyMateriaSource) 
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria*)
{

}

AMateria*	MateriaSource::createMateria(std::string const & type)
{

}
