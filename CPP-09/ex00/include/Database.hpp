
#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Database
{
	private:
		std::ifstream	_db;	
		std::ifstream	_inputFile;
	public:
		Database();
		~Database();
		Database(const Database& copy);
		Database& operator=(const Database& copy);
		Database(const std::string& path);
		void		display() const;
		std::string	findDate(const std::string& line) const;
		double		extractValue(const std::string& line) const;
};


