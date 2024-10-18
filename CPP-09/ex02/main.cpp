#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		return 1;
	std::string	input;
	for (int i = 1; i < ac; i++)
	{
		input += av[i];
		if (i != ac - 1)
			input += " ";
	}
	try
	{
		vectorMerge	vectorSort(input);
		vectorSort.recursiveSort();

		listMerge	listSort(input);
		listSort.recursiveSort();
		return 0;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
