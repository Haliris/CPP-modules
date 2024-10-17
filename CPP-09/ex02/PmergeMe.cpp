#include "PmergeMe.hpp"
#include <cstddef>
#include <sstream>

vectorMerge::vectorMerge()
{
}

vectorMerge::~vectorMerge()
{
}

vectorMerge::vectorMerge(const vectorMerge& copy)
{
    *this = copy;
}

vectorMerge& vectorMerge::operator=(const vectorMerge& copy)
{
    if (this != &copy)
    {
    }
    return *this;
}

listMerge::listMerge()
{
}

listMerge::~listMerge()
{
}

listMerge::listMerge(const listMerge& copy)
{
    *this = copy;
}

listMerge& listMerge::operator=(const listMerge& copy)
{
    if (this != &copy)
    {
    }
    return *this;
}

///////////////////
// BOILER PLATES //
///////////////////

void	vectorMerge::sortPairs()
{
	std::vector<std::pair<int, int>>::iterator it;
	
	for (it = _pairs.begin(); it != _pairs.end(); it++)
	{
		if (it->first < it->second)
		{
			int	temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

bool	vectorMerge::checkNum(const std::string& token)
{
	size_t	i = 0;
	
	if (token[0] == '-' || token[0] == '+')
		i++;
	while (i < token.size())
	{
		if (!isdigit(token[i]))
			return false;
		i++;
	}
	return true;
}

bool	vectorMerge::checkDuplicates(int num)
{
	std::vector<std::pair<int, int>>::const_iterator it;

	for (it = _pairs.begin(); it != _pairs.end(); it++)
	{
		if (num == it->first || num == it->second)
			return true;
	}
	return false;
}

void	vectorMerge::initPairs()
{
	int	num1, num2;
	size_t	index = 0;
	std::vector<int>::iterator	it = _smallElements.begin();	
	while (it != _smallElements.end())
	{
		if (index % 2 == 0)
	  	{
			num1 = *it;
			it = _smallElements.erase(it);
		}
		else if (index % 2 == 1)
		{
			num2 = *it;
			_pairs.push_back(std::make_pair(num1, num2));	
			it = _smallElements.erase(it);
		}
		index++;
	} 
	if (index % 2 == 0)
		_orphan = num1;
}

void	vectorMerge::updatePairs()
{
	std::vector<std::pair<int, int>>::iterator	it = _pairs.begin();
	_smallElements.reserve(_pairs.size() / 2);
	_bigElements.reserve(_pairs.size() / 2);
	while (it != _pairs.end())
	{
		_smallElements.push_back(it->second);
		_bigElements.push_back(it->first);
		it = _pairs.erase(it);
	}

	std::vector<int>::iterator	bigIt;
	size_t						index = 0;
	int							num1, num2;
	
	for (bigIt = _bigElements.begin(); bigIt != _bigElements.end(); bigIt++)
	{
		if (index % 2 == 0)
			num1 = *bigIt;
		else
		{
			num2 = *bigIt;
			_pairs.push_back(std::make_pair(num1, num2));
		}
		index++;
	}	
}

void	vectorMerge::insertElements()
{
	std::vector<int>	sortedVector;
	std::vector<int>::const_iterator smallIt = _smallElements.begin();

	sortedVector.reserve(_smallElements.size() + (_pairs.size() * 2));
	for (std::vector<std::pair<int, int>>::const_iterator it = _pairs.begin(); it != _pairs.end(); it++)
	{
		sortedVector.push_back(it->first);
		sortedVector.push_back(it->second);
	}
	while (smallIt != _smallElements.end())
	{
		int	left = 0, right = sortedVector.size() - 1;
		int	diff = INT_MAX;
		int	prospect = 0;
		while (left <= right)
		{
			int	mid = left + (right - left) / 2;
			if (*smallIt - sortedVector[mid] < diff)
			{
				diff = *smallIt - sortedVector[mid];
				prospect = mid;
			}
			if (*smallIt > mid)
				right = mid - 1;
			else
				left = mid + 1;
		}
		smallIt = _smallElements.erase(smallIt);
	}
}

void	vectorMerge::recursiveSort()
{
	while (_pairs.size() > 2)
	{
		sortPairs();
		updatePairs();
		recursiveSort();
	}
	insertElements();
}

vectorMerge::vectorMerge(const std::string&	input)
{
	std::stringstream					inputStream(input);
	std::string							token;
	int									num;

	_smallElements.reserve(input.size() / 2);
	_pairs.reserve(input.size() / 4);
	while (getline(inputStream, token, ' '))
	{
		if (checkNum(token) == false)
			throw std::runtime_error("Error: non numeric argument: " + token);
		num = atoi(token.c_str());
		if (checkDuplicates(num) == true)
			throw std::runtime_error("Error: no dupliactes allowed: " + token);
		_smallElements.push_back(num);
	}
	initPairs();
}
