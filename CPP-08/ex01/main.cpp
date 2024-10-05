#include "Span.hpp"

int main(void)
{
	Span sp = Span(5);
	Span ip = Span(10000);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
//	sp.print();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::vector<int> v_test;
	v_test.reserve(10000);
	for (int i = 0; i < 9999; i++)
			v_test.push_back(i);
	ip.addNumber(v_test.begin(), v_test.end());
//	ip.print();
	std::cout << ip.shortestSpan() << std::endl;
	std::cout << ip.longestSpan() << std::endl;
	return 0;
}
