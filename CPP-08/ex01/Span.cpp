
#include "Span.hpp"
#include <cstdint>

Span::Span()
{
	_capacity = 0;
	//throw ??
}

Span::Span(uint32_t	n)
{
	_capacity = n;
	this->_buff = std::vector<int>(n);
}

Span::~Span()
{
}

Span::Span(const Span& copy)
{
    *this = copy;
}

Span& Span::operator=(const Span& copy)
{
    if (this != &copy)
    {
		this->_capacity = copy._capacity;
		this->_size	= copy._size;
		this->_buff = copy._buff; //test this fucking shit, 99% a shallow copy;
    }
    return *this;
}

void	Span::addNumber(int value)
{
	if (size == capacity)
		throw
	_size++;
	_buff.push_back(value);
}

uint32_t	Span::longestSpan() const
{

}

uint32_t	Span::shortestSpan() const
{

}
