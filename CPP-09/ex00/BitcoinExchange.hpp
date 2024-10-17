
#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits.h>
#include <cstddef>
#include <string>
#include <stdint.h>
#include <map>
#define DB_PATH "data.csv"

class Database
{
	private:
		Database() {};
		std::map<std::string, double>	_db;	
		const std::string				_argPath;
	public:
		~Database();
		Database(const Database& copy);
		Database& operator=(const Database& copy);
		Database(const std::string& path);
		void		display() const;
		std::string	findDate(const std::string& line) const;
		double		extractValue(const std::string& line) const;
		double		doMath(const std::string date, const double initialValue) const;
		uint32_t	convertDate(const std::string& date) const;
};


