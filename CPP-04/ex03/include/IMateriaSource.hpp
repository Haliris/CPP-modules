#ifndef IMATERIA_SOURCE
# define IMATERIA_SOURCE
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

class MateriaSource : IMateriaSource
{
	private:
		AMateria*	materias[4];
		int			materia_nb;
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& copyMateriaSource);
		MateriaSource&	operator=(const MateriaSource& copyMateriaSource); 
		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};


#endif