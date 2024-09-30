#include "Iter.hpp"

void	myupper(char& c)
{
	if (isalpha(c) && c >= 'a')
		c -=32;
}

void	mylower(char& c)
{
	if (isalpha(c) && c <= 'Z')
		c +=32;
}

void	mybzero(int& c)
{
	c = 0;
}

int main(void)
{
	char	str[12] = "Hello World";
	int		i_arr[3] = {12, 02, 1998};

	std::cout << "Str: " << str << std::endl;
	iter(str, 12, &myupper);
	iter(str, 12, &myprint<char>);
	std::cout << std::endl;
	iter(str, 12, &mylower);
	iter(str, 12, &myprint<char>);
	std::cout << std::endl;
	std::cout << "------" << std::endl;
	std::cout << "Int array tests" << std::endl;
	iter(i_arr, 3, &myprint<int>);
	std::cout << std::endl;
	iter(i_arr, 3, &mybzero);
	iter(i_arr, 3, &myprint<int>);
	std::cout << std::endl;
}
