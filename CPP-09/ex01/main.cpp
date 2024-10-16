#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		Equation equation(av[1]);
		equation.process();
		return 0;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
