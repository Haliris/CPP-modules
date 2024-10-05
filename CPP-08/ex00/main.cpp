#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v(5);
	for (int i = 0; i < 42 * 5; i+= 42)
		v.push_back(i);
	try 
	{
	std::vector<int>::const_iterator vec_found = easyfind(v, 40);
	std::cout << "vector test " <<  *vec_found << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught" << std::endl;
	}
}
