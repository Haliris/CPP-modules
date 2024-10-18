#include "PmergeMe.hpp"
#include <algorithm>

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
	std::vector<std::pair<int, int> >::iterator it;
	
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
	std::vector<std::pair<int, int> >::const_iterator it;

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
	if (index % 2 == 1)
		_smallElements.push_back(num1);
}

void	vectorMerge::updatePairs()
{
	std::vector<std::pair<int, int> >::iterator	it = _pairs.begin();
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
	_bigElements.erase(_bigElements.begin(), _bigElements.end());
}

void	vectorMerge::insertElements()
{
	std::vector<int>	sortedVector;
	std::vector<int>::iterator smallIt = _smallElements.begin();

	sortedVector.reserve(_smallElements.size() + (_pairs.size() * 2));
	for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++)
	{
		int	temp;
		if (it->first > it->second)
		{
			temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
		sortedVector.push_back(it->first);
		sortedVector.push_back(it->second);
	}
	while (_smallElements.size())
	{
		int	left = 0, right = sortedVector.size() - 1;
		int	diff = INT_MAX;
		int	prospect = 0;
		while (right >= left)
		{
			int	mid = left + (right - left) / 2;
			if (abs(*smallIt - sortedVector[mid]) < diff)
			{
				diff = abs(*smallIt - sortedVector[mid]);
				if (*smallIt > sortedVector[mid])
					prospect = mid + 1;
				else
					prospect = mid;
			}
			if (*smallIt > sortedVector[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		sortedVector.insert(sortedVector.begin() + prospect, *smallIt);
		smallIt = _smallElements.erase(smallIt);
	}
	std::cout << "After:\t";
	for (size_t i = 0; i < sortedVector.size(); i++)
	{
		if (i == 4)
	 	 {
			std::cout << "[...]";
			break;
		}
		else
			std::cout << sortedVector[i] << " ";
	}
	std::cout << std::endl;
	_timerEnd = clock();
	double	time_taken = double(_timerEnd - _timerStart) * 10000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of\t" << _range << " elements with std::vector : "<< std::fixed << time_taken << " ms" << std::setprecision(5) << std::endl;
//	if (is_sorted(sortedVector.begin(), sortedVector.end()))
//		std::cerr << "Success!" << std::endl;
//	else
//		std::cerr << "Failure :(" << std::endl;
}

void	vectorMerge::recursiveSort()
{
	while (_pairs.size() >= 2)
	{
		sortPairs();
		updatePairs();
		recursiveSort();
		return ;
	}
	insertElements();
}

vectorMerge::vectorMerge(const std::string&	input)
{
	std::stringstream					inputStream(input);
	std::string							token;
	int									num;

	_timerStart = clock();
	_range = input.size();
	_smallElements.reserve(input.size());
	while (getline(inputStream, token, ' '))
	{
		if (checkNum(token) == false)
			throw std::runtime_error("Error: non numeric argument: " + token);
		num = atoi(token.c_str());
		if (checkDuplicates(num) == true)
			throw std::runtime_error("Error: no dupliactes allowed: " + token);
		_smallElements.push_back(num);
	}
	std::cout << "Before:\t ";
	for (size_t i = 0; i < _smallElements.size(); i++)
	{
		if (i == 4)
		{
			std::cout << "[...]";
			break;
		}
		else
			std::cout << _smallElements[i] << " ";
	}
	std::cout << std::endl;
	_pairs.reserve(_smallElements.size()/ 2);
	initPairs();
	_range = _pairs.size() * 2 + _smallElements.size();
}
