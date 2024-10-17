#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		return 1;
	std::string	input;
	for (int i = 1; i < ac; i++)
		input += av[1];
	try
	{
		vectorMerge	vectorSort(input);
		vectorSort.recursiveSort();
		return 0;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
