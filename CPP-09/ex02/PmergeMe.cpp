#include "PmergeMe.hpp"
#include <algorithm>

///////////////////
// BOILER PLATE  //
///////////////////

bool	comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) 
{
    return a.first < b.first;
}

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
// VECTOR MERGE //
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
	std::sort(_pairs.begin(), _pairs.end(), comparePairs);
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
	std::vector<int>::const_iterator it;

	for (it = _smallElements.begin(); it != _smallElements.end(); it++)
	{
		if (num == *it)
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
		if (it->second != -1)
			_smallElements.push_back(it->second);
		_bigElements.push_back(it->first);
		it = _pairs.erase(it);
	}
	for (size_t i = 0; i < _bigElements.size(); i++)
	{
		if (i % 2 == 0)
			_pairs.push_back(std::make_pair(_bigElements[i], -1));
		else
			_pairs[_pairs.size() - 1].second = _bigElements[i];
	}
	_bigElements.erase(_bigElements.begin(), _bigElements.end());
}

const std::vector<int>	vectorMerge::GenerateJacobstahlSeq(int n)
{
	std::vector<int>	sequence;
	sequence.reserve(2 + n);
	sequence.push_back(0);
	sequence.push_back(1);
	while (sequence.back() < n)
	{
		int size = sequence.size();
		sequence.push_back(sequence[size - 1] + 2 * sequence[size - 2]);
	}
	return sequence;
}

void	vectorMerge::insertElements()
{
	std::vector<int>	sortedVector;

	sortedVector.reserve(_smallElements.size() + _pairs.size() * 2);
	for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++)
	{
		sortedVector.push_back(it->first);
		sortedVector.push_back(it->second);
	}
	const std::vector<int>	jacobSequence = GenerateJacobstahlSeq(_smallElements.size());
	std::vector<bool> inserted(_smallElements.size(), false);
	for (size_t i = 1; i < jacobSequence.size() && jacobSequence[i] < static_cast<int>(_smallElements.size()) ; i++)
	{
		int start = jacobSequence[i];
		int prev = (i > 0) ? jacobSequence[i - 1] : 0;
		for (int idx = start; idx > prev; --idx)
		{
			if (idx < static_cast<int>(_smallElements.size()) && !inserted[idx]) 
			{
				int pos = binarySearch(sortedVector, _smallElements[idx], 0, sortedVector.size());
				sortedVector.insert(sortedVector.begin() + pos, _smallElements[idx]);
				inserted[idx] = true;
			}
		}
	}
	for (size_t i = 0; i < _smallElements.size(); i++)
	{
		if (!inserted[i])
		{
			int pos = binarySearch(sortedVector, _smallElements[i], 0, sortedVector.size());
			sortedVector.insert(sortedVector.begin() + pos, _smallElements[i]);
		}
	}
	std::cout << "After:\t";
	for (size_t i = 0; i < sortedVector.size(); i++)
	{
//		if (i == 4)
//	 	 {
//			std::cout << "[...]";
//			break;
//		}
//		else
			std::cout << sortedVector[i] << " ";
	}
	std::cout << std::endl;
	_timerEnd = clock();
	double	time_taken = double(_timerEnd - _timerStart) * 10000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of\t" << _range << " elements with std::vector : "<< std::fixed << time_taken << " ms" << std::setprecision(5) << std::endl;
	if (is_sorted(sortedVector.begin(), sortedVector.end()))
		std::cerr << "Success!" << std::endl;
	else
		std::cerr << "Failure :(" << std::endl;
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
			throw std::runtime_error("Error: no duplicates allowed: " + input + " => " + token);
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

///////////////////
// LIST MERGE    //
///////////////////

void	listMerge::sortPairs()
{
	std::list<std::pair<int, int> >::iterator it;
	
	for (it = _pairs.begin(); it != _pairs.end(); it++)
	{
		if (it->first < it->second)
		{
			int	temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
	_pairs.sort(comparePairs);
}

bool	listMerge::checkNum(const std::string& token)
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

bool	listMerge::checkDuplicates(int num)
{
	std::list<int>::const_iterator it;

	for (it = _smallElements.begin(); it != _smallElements.end(); it++)
	{
		if (num == *it)
			return true;
	}
	return false;
}

void	listMerge::initPairs()
{
	int	num1, num2;
	size_t	index = 0;
	std::list<int>::iterator	it = _smallElements.begin();	
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

void	listMerge::updatePairs()
{
	std::list<std::pair<int, int> >::iterator	it = _pairs.begin();
	while (it != _pairs.end())
	{
		if (it->second != -1)
			_smallElements.push_back(it->second);
		_bigElements.push_back(it->first);
		it = _pairs.erase(it);
	}
	for (size_t i = 0; i < _bigElements.size(); i++)
	{
		std::list<int>::iterator cursor = _bigElements.begin();
		std::advance(cursor, i);
		if (i % 2 == 0)
			_pairs.push_back(std::make_pair(*cursor, -1));
		else
			_pairs.back().second = *cursor;
	}
	_bigElements.erase(_bigElements.begin(), _bigElements.end());
}

const std::vector<int>	listMerge::GenerateJacobstahlSeq(int n)
{
	std::vector<int>	sequence;
	sequence.reserve(2 + n);
	sequence.push_back(0);
	sequence.push_back(1);
	while (sequence.back() < n)
	{
		int size = sequence.size();
		sequence.push_back(sequence[size - 1] + 2 * sequence[size - 2]);
	}
	return sequence;
}

void	listMerge::insertElements()
{
	std::list<int>	sortedList;

	for (std::list<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++)
	{
		sortedList.push_back(it->first);
		sortedList.push_back(it->second);
	}
	std::vector<bool> inserted(_smallElements.size(), false);
	const std::vector<int>	jacobSequence = GenerateJacobstahlSeq(_smallElements.size());
	for (size_t i = 1; i < jacobSequence.size() && jacobSequence[i] < static_cast<int>(_smallElements.size()) ; i++)
	{
		int start = jacobSequence[i];
		int prev = (i > 0) ? jacobSequence[i - 1] : 0;
		for (int idx = start; idx > prev; --idx)
		{
			if (idx < static_cast<int>(_smallElements.size()) && !inserted[idx]) 
			{
				std::list<int>::iterator lt = _smallElements.begin();
				std::list<int>::iterator cursor = _smallElements.begin();
				std::advance(lt, idx);
				int pos = binarySearch(sortedList, *lt, 0, sortedList.size());
				std::advance(cursor, pos);
				sortedList.insert(cursor, *lt);
				inserted[idx] = true;
			}
		}
	}
	for (size_t i = 0; i < _smallElements.size(); i++)
	{
		if (!inserted[i])
		{
			std::list<int>::iterator lt = _smallElements.begin();
			std::list<int>::iterator cursor = _smallElements.begin();
			std::advance(lt, i);
			int pos = binarySearch(sortedList, *lt, 0, sortedList.size());
			std::advance(cursor, pos);
			sortedList.insert(cursor, *lt);
		}
	}
	std::cout << "After:\t";
	for (size_t i = 0; i < sortedList.size(); i++)
	{
	  	std::list<int>::iterator it = sortedList.begin();
		std::advance(it, i);
//		if (i == 4)
//	 	 {
//			std::cout << "[...]";
//			break;
//		}
//		else
			std::cout << *it << " ";
	}
	std::cout << std::endl;
	_timerEnd = clock();
	double	time_taken = double(_timerEnd - _timerStart) * 10000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of\t" << _range << " elements with std::list : "<< std::fixed << time_taken << " ms" << std::setprecision(5) << std::endl;
	if (is_sorted(sortedList.begin(), sortedList.end()))
		std::cerr << "Success!" << std::endl;
	else
		std::cerr << "Failure :(" << std::endl;
}

void	listMerge::recursiveSort()
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

listMerge::listMerge(const std::string&	input)
{
	std::stringstream					inputStream(input);
	std::string							token;
	int									num;

	_timerStart = clock();
	while (getline(inputStream, token, ' '))
	{
		if (checkNum(token) == false)
			throw std::runtime_error("Error: non numeric argument: " + token);
		num = atoi(token.c_str());
		if (checkDuplicates(num) == true)
			throw std::runtime_error("Error: no duplicates allowed: " + input + " => " + token);
		_smallElements.push_back(num);
	}
	_range = _smallElements.size();
	initPairs();
}
