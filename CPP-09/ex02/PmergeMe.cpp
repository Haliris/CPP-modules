#include "PmergeMe.hpp"

///////////////////
// BOILER PLATE  //
///////////////////


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

	int							num1, num2;
	for (size_t i = 0; i < _bigElements.size(); i++)
	{
		if (i % 2 == 0)
	  	{
			num1 = _bigElements[i];
			_pairs.push_back(std::make_pair(num1, -1));
		}
		else
		{
			num2 = _bigElements[i];
			_pairs[_pairs.size() - 1].second = num2;
		}
	}
	_bigElements.erase(_bigElements.begin(), _bigElements.end());
}

const std::vector<int>	vectorMerge::GenerateJacobstahlSeq(int n)
{
	std::vector<int>	sequence;
	sequence.reserve(2 + 1);
	sequence.push_back(0);
	sequence.push_back(1);
	std::cerr << "Jacob expected size: " << n << std::endl;
	while (sequence.back() < n)
	{
		int	next = sequence.back() + 2 * sequence[sequence.size() - 2];
		if (next >= n)
			break;
		sequence.push_back(next);
		std::cerr << "back: " << sequence.back() << std::endl;
	}
	return sequence;
}

void	vectorMerge::insertElements()
{
	std::vector<int>	sortedVector;

	sortedVector.reserve(_smallElements.size() + _pairs.size() * 2);
	std::cerr << "Small: ";
	for (size_t i = 0; i < _smallElements.size(); i++)
		std::cerr << _smallElements[i] << " ";
	std::cerr << std::endl;
	std::cerr << "pairs:";
	for (size_t i = 0; i < _pairs.size(); i++)
	{
		std::cerr << "first: " << _pairs[i].first << " ";
		std::cerr << "second: " << _pairs[i].second << " ";
	}
	std::cerr << std::endl;
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
	const std::vector<int>	jacobSequence = GenerateJacobstahlSeq(_smallElements.size());
	for (size_t i = jacobSequence.size() - 1; i > 0; i--)
	{
		size_t pos = jacobSequence[i] - 1;
		if (pos < sortedVector.size())
		{
			std::vector<int>::iterator it = std::lower_bound(sortedVector.begin(), sortedVector.end(), _smallElements[pos]);
			sortedVector.insert(it, _smallElements[pos]);
		}
	}
	for (size_t i = 0; i < _smallElements.size(); i++)
	{
		if (std::find(jacobSequence.begin(), jacobSequence.end(), i + 1) == jacobSequence.end())
		{
			std::vector<int>::iterator it = std::lower_bound(sortedVector.begin(), sortedVector.end(), _smallElements[i]);
			std::cerr << "Inserting: " << _smallElements[i] << std::endl;
			sortedVector.insert(it, _smallElements[i]);
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
	sequence.reserve(n);
	sequence.push_back(0);
	if (n > 1)
		sequence.push_back(1);
	while (sequence.back() < n)
	{
		int	next = sequence.back() + 2 * sequence[sequence.size() - 2];
		if (next >= n)
			break;
		sequence.push_back(next);
	}
	return sequence;
}

void	listMerge::insertElements()
{
	std::list<int>	sortedlist;
	std::list<int>::iterator smallIt = _smallElements.begin();

	for (std::list<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++)
	{
		int	temp;
		if (it->first > it->second)
		{
			temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
		sortedlist.push_back(it->first);
		sortedlist.push_back(it->second);
	}
	while (_smallElements.size())
	{
		int	left = 0, right = sortedlist.size() - 1;
		int	diff = INT_MAX;
		int	prospect = 0;
		while (right >= left)
		{
			int	mid = left + (right - left) / 2;
			std::list<int>::iterator cursor = sortedlist.begin();
			std::advance(cursor, mid);
			if (abs(*smallIt - *cursor) < diff)
			{
				diff = abs(*smallIt - *cursor);
				if (*smallIt > *cursor)
					prospect = mid + 1;
				else
					prospect = mid;
			}
			if (*smallIt > *cursor)
				left = mid + 1;
			else
				right = mid - 1;
		}
		std::list<int>::iterator cursor = sortedlist.begin();
		std::advance(cursor, prospect);
		sortedlist.insert(cursor, *smallIt);
		smallIt = _smallElements.erase(smallIt);
	}
	std::cout << "After:\t";
	for (size_t i = 0; i < sortedlist.size(); i++)
	{
	  	std::list<int>::iterator it = sortedlist.begin();
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
	if (is_sorted(sortedlist.begin(), sortedlist.end()))
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
