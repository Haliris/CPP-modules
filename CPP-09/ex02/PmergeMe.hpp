
#pragma once
#include <stdint.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <sstream>
#include <limits.h>
#include <math.h>
#include <ctime>
#include <iomanip>
#include <algorithm>

class vectorMerge
{
	private:
		vectorMerge(const vectorMerge& copy);
		vectorMerge& operator=(const vectorMerge& copy);
		vectorMerge();
		std::vector<int>					_smallElements;
		std::vector<int>					_bigElements;
		std::vector<std::pair<int, int> >	_pairs;
		uint32_t							_range;
		clock_t								_timerStart, _timerEnd;
	public:
		vectorMerge(const std::string& input);
		~vectorMerge();
		bool		checkNum(const std::string&	token);
		bool		checkDuplicates(int num);
		void		initPairs();
		void		updatePairs();
		void		sortPairs();
		void		recursiveSort();
		void		insertElements();
};

class listMerge
{
	private:
		listMerge();
		listMerge(const listMerge& copy);
		listMerge& operator=(const listMerge& copy);
		std::list<std::pair<int, int> >		_pairs;
		std::list<int>						_smallElements;
		std::list<int>						_bigElements;
		uint32_t							_range;
		clock_t								_timerStart, _timerEnd;
	public:
		listMerge(const std::string& input);
		~listMerge();
		bool		checkNum(const std::string&	token);
		bool		checkDuplicates(int num1);
		void		initPairs();
		void		updatePairs();
		void		sortPairs();
		void		recursiveSort();
		void		insertElements();
};


template <typename Iterator>
bool is_sorted(Iterator first, Iterator last) {
    if (first == last) return true;
    Iterator next = first;
    ++next;
    while (next != last) {
        if (*next < *first) {
            return false;
        }
        ++first;
        ++next;
    }
    return true;
}
