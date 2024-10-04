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
	const int const_arr[3] = {0, 1, 2};

	std::cout << "Str: " << str << std::endl;
	iter(str, 12, &myupper);
	iter(str, 12, &myprint<char>);
	std::cout << std::endl;
	iter(str, 12, &mylower);
	iter(str, 12, &myprint<char>);
	std::cout << std::endl;
	std::cout << "------" << std::endl;
	std::cout << "Int array tests";
	for (int i = 0; i < 3; i++)
		std::cout << " " << i_arr[i];
	std::cout << std::endl;
	iter(i_arr, 3, &myprint<int>);
	std::cout << std::endl;
	iter(i_arr, 3, &mybzero);
	iter(i_arr, 3, &myprint<int>);
	std::cout << std::endl;
	std::cout << "Const array test" << std::endl;
	iter(const_arr, 3, &myprint<int>);
	std::cout << std::endl;
//	iter(const_arr, 3, &mybzero);
//	std::cout << std::endl;
}
