#include "MutantStack.hpp"
#include <list>

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	//////////////
	///Copy_test//
	//////////////
	std::cout << std::endl << "list Test" << std::endl;
	std::list<int> s;
	s.push_front(5);
	s.push_front(17);
	std::cout << s.front() << std::endl;
	s.pop_front();
	std::cout << s.size() << std::endl;
	s.push_back(3);
	s.push_back(5);
	s.push_back(737);
	s.push_back(0);
	{
		std::list<int>::iterator it = s.begin();
		std::list<int>::iterator ite = s.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
