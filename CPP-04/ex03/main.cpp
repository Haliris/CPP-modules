#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int	main(void)
{
	MateriaSource*	materia_stash;
	Ice*			ice_materia;	
	Cure*			cure_materia;
	Character*		bob;

	materia_stash = new(std::nothrow) MateriaSource();
	ice_materia = new(std::nothrow) Ice();
	cure_materia = new(std::nothrow) Cure();
	bob = new(std::nothrow) Character("Bob");
	if (ice_materia == NULL || cure_materia == NULL || materia_stash == NULL)
		return (EXIT_FAILURE);
	delete bob;
	delete ice_materia;
	delete cure_materia;
	delete materia_stash;
}
