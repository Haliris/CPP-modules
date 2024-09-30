#include "Template.hpp"

int main (void)
{
	int a = 42;
	int b = 0;
	float c = 42.5;
	float d = 0.0;

	std::cout << "Begin" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "c: " << c << " d: " << d << std::endl;
	swap(a, b);
	swap(c, d);
	std::cout << "----------------" << std::endl;
	std::cout << "After swap" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << "c: " << c << " d: " << d << std::endl;
	std::cout << "min: " << min(a, b) << std::endl; 
	std::cout << "max: " << max(a, b) << std::endl; 
	std::cout << "min: " << min(c, d) << std::endl; 
	std::cout << "max: " << max(c, d) << std::endl; 
}
