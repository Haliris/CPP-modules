#include "Span.hpp"
# include <stdlib.h>
# include <time.h>

int	random_num()
{
	return (rand() % 100000);
}

int main(void)
{
	try
	{
		srand(static_cast<unsigned int>(time(0)));
		Span sp = Span(5);
		Span rand_test = Span(10);
		Span ip = Span(10000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
//		sp.addNumber(10);
		//	sp.print();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "10 test" << std::endl;
		std::vector<int> h_test;
		for (int i = 0; i < 9; i++)
			h_test.push_back(random_num());
		rand_test.addNumber(h_test.begin(), h_test.end());
		std::cout << rand_test.shortestSpan() << std::endl;
		std::cout << rand_test.longestSpan() << std::endl;
		std::cout << "10000 test" << std::endl;
		std::vector<int> v_test;
		v_test.reserve(10000);
		for (int i = 0; i < 9999; i++)
			v_test.push_back(random_num());
		ip.addNumber(v_test.begin(), v_test.end());
		//	ip.print();
		std::cout << ip.shortestSpan() << std::endl;
		std::cout << ip.longestSpan() << std::endl;
		std::cout << "Copy test" << std::endl;
		Span copy_sp(sp);
		std::cout << copy_sp.shortestSpan() << std::endl;
		std::cout << copy_sp.longestSpan() << std::endl;
		std::cout << "MEGA TEST" << std::endl;
		Span megasp = Span(50000);
		std::vector<int> megav_test;
		megav_test.reserve(50000);
		for (int i = 0; i < 49999; i++)
			megav_test.push_back(random_num());
		megasp.addNumber(megav_test.begin(), megav_test.end());
		std::cout << megasp.shortestSpan() << std::endl;
		std::cout << megasp.longestSpan() << std::endl;
		return 0;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
