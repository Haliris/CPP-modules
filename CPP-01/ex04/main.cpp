/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:48:35 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/21 18:28:16 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>



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
		if (line == to_replace)
			line = replacement;
		ReplaceFile << line << std::endl;
	}
	InFile.close();
	ReplaceFile.close();
	return (0);
}
