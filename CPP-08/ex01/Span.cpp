#include "Span.hpp"

Span::Span() : _capacity(0)
{
}

Span::Span(int n) : _capacity(n)
{
	_buff.reserve(_capacity);
	_size = 0;
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
		throw std::out_of_range("[SPAN] out of range");
	_size++;
	_buff.push_back(value);
}

void	Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (_size == _capacity)
		throw std::out_of_range("[SPAN] out of range");
	if (std::distance(first, last) + _size >= _capacity)
		throw std::out_of_range("[SPAN] out of range");
	_buff.insert(_buff.end(), first , last);
	_size += std::distance(first, last);
}

uint32_t	Span::longestSpan() const
{
	if (_size <= 1)
		throw std::out_of_range("[SPAN] out of range");
	std::vector<int> sorted(_buff);
	std::sort(sorted.begin(), sorted.end());
	return (*(sorted.end() - 1) - *sorted.begin());
}

uint32_t	Span::shortestSpan() const
{
	uint32_t	min = INT_MAX;

	if (_size <= 1)
		throw std::out_of_range("[SPAN] out of range");
	std::vector<int> sorted(_buff);
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator it = sorted.begin();
	while (it != sorted.end() - 1)
	{
		if (my_abs(*it - (*(it + 1))) < min)
				min = my_abs(*it - *(it + 1));
		++it;
	}
	return min;
}

void	Span::print() const
{
	if (_size == 0)
		return ;
	std::vector<int>::const_iterator it = _buff.begin();
	while (it != _buff.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
}
