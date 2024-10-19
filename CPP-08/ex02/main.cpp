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
	std::cout << mstack.size() << std::endl;
	
	//////////////
	///Copy_test//
	//////////////

	std::cout << std::endl << "copy Test" << std::endl;
	MutantStack<int> copystack(mstack);
	{
		MutantStack<int>::iterator it = copystack.begin();
		MutantStack<int>::iterator ite = copystack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << copystack.size() << std::endl;
	
	//////////////
	///List_test//
	//////////////

	std::cout << std::endl << "list Test" << std::endl;
	std::list<int> l;
	l.push_front(5);
	l.push_front(17);
	std::cout << l.front() << std::endl;
	l.pop_front();
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);
	{
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
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
