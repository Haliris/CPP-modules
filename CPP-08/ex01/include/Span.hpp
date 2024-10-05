
#pragma once
#include <cstdint>
#include <vector>
#include <stdint.h>

class Span
{
	private:
		uint32_t			_capacity;
		uint32_t			_size;
		std::vector<int>	_buff;
		Span();
	public:
		Span(uint32_t n);
		~Span();
		Span(const Span& copy);
		Span&	operator=(const Span& copy);
		void		addNumber(int value);
		uint32_t	longestSpan() const;
		uint32_t	shortestSpan() const;
};
