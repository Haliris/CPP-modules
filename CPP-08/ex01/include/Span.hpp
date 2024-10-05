
#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include <stdint.h>
#include <limits.h>

class Span
{
	private:
		const uint32_t			_capacity;
		uint32_t				_size;
		std::vector<int>		_buff;
		Span();
	public:
		Span(uint32_t n);
		~Span();
		Span(const Span& copy);
		Span&	operator=(const Span& copy);
		void		addNumber(int value);
		void		addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
		uint32_t	longestSpan() const;
		uint32_t	shortestSpan() const;
};

template<typename T>
T my_abs(T value)
{
	return (value > 0 ? value : -value);
};
