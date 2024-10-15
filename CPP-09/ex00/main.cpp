#include "Database.hpp" 

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	try 
	{
		Database	Data(av[1]);
		Data.display();
		return 0;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
