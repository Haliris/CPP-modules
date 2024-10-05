#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
		MutantStack& operator=(const MutantStack& copy)
		{
			if (*this != copy)
			{
				std::stack<T>::operator=(copy);
			}
			return *this;
		}
		typename std::stack<T>::container_type::iterator begin()
		{
			return this->c.begin();
		}
		typename std::stack<T>::container_type::iterator end()
		{
			return this->c.end();
		}
};


