
#include "Span.hpp"
#include <cstdint>

Span::Span() : _capacity(0)
{
	//throw ??
}

Span::Span(uint32_t	n) : _capacity(n)
{
	this->_buff = std::vector<int>(_capacity);
}

Span::~Span()
{
}

Span::Span(const Span& copy) : _capacity(copy._capacity)
{
    *this = copy;
}

Span& Span::operator=(const Span& copy)
{
    if (this != &copy)
    {
		this->_size	= copy._size;
		this->_buff = copy._buff; //test this fucking shit, 99% a shallow copy;
    }
    return *this;
}

void	Span::addNumber(int value)
{
	if (_size == _capacity)
		throw
	_size++;
	_buff.push_back(value);
}

void	Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (_size == _capacity)
		thow;
}

uint32_t	Span::longestSpan() const
{
	uint32_t	max = INT_MIN;
	if (_size <= 1)
		throw;
	for (int i = 0; i < _size; i++)
	{
		for (int j = i + 1; j < _size; j++)
		{
			if (my_abs(_buff[i] - _buff[j]) > max)
				max = my_abs(_buff[i] - _buff[j]);
		}
	}
	return max;
}

uint32_t	Span::shortestSpan() const
{
	uint32_t	min = INT_MAX;
	if (_size <= 1)
		throw;
	for (int i = 0; i < _size; i++)
	{
		for (int j = i + 1; j < _size; j++)
		{
			if (my_abs(_buff[i] - _buff[j]) < min)
				min = my_abs(_buff[i] - _buff[j]);
		}
	}
	return min;
}
