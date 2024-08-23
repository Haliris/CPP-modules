/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:48:35 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 11:24:46 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	find_and_replace(std::string line, std::string to_replace, std::string replacement)
{
	size_t	pos;

	while ((pos = line.find(to_replace)) != std::string::npos)
	{
		line.erase(pos, to_replace.length());
		line.insert(pos, replacement);
		pos += replacement.length();
	}
	std::cout << line << std::endl;
	return (line);
}

int	main(int ac, char **av)
{
	std::string		infile;
	std::string		to_replace;
	std::string		replacement;
	std::string		line;
	std::ifstream	InFile;
	std::ofstream	ReplaceFile;

	if (ac != 4)
	{
		std::cout << "Wrong nb of arguments. Expected [filepath] [string to replace] [string replacement]" << std::endl;
		return (1);
	}
	infile = av[1];
	to_replace = av[2];
	replacement = av[3];
	InFile.open(infile.c_str());
	if (!InFile)
	{
		std::cout << "Error: open: could not open infile" << std::endl;
		return (1);
	}
	infile = infile + ".replace";
	ReplaceFile.open(infile.c_str());
	if (!ReplaceFile)
	{
		std::cout << "Error: open: could not open replace file" << std::endl;
		InFile.close();
		return (1);
	}
	while (std::getline(InFile, line))
	{
		line = find_and_replace(line, to_replace, replacement);
		ReplaceFile << line << std::endl;
	}
	InFile.close();
	ReplaceFile.close();
	return (0);
}
