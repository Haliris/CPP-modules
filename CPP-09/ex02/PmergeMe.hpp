
#pragma once
#include <ctype.h>
#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <sstream>


class vectorMerge
{
	private:
		vectorMerge(const vectorMerge& copy);
		vectorMerge& operator=(const vectorMerge& copy);
		vectorMerge();
		std::vector<std::pair<int, int>>	_pairs;
		int									_orphan;
	public:
		vectorMerge(const std::string&	input);
		~vectorMerge();
		bool	checkNum(const std::string&	token);
};

class listMerge
{
	private:
		listMerge();
		listMerge(const listMerge& copy);
		listMerge& operator=(const listMerge& copy);
		std::list<std::pair<int, int>>		_pairs;
		int									_orphan;
	public:
		listMerge(const std::string&	input);
		~listMerge();
		bool	checkNum(const std::string&	token);
};


