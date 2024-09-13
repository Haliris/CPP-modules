#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	private:
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& copyCat);
		WrongCat& operator=(const WrongCat& copyCat);
		void				makeSound() const;
};
#endif
