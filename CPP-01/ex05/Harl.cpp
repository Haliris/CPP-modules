/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:00:21 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/23 11:27:52 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love working in Made, Made has Moulinette the cat, Made is awesome!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Made is crawling with centipedes, I cannot believe Made is overrun with these annoying pesky bugs!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve a workspace free of bugs, I have been working on my minishell for 2 years and never had to suffer from such insects!" << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable, that is it, I am blackholing!" << std::endl;
}

//pair : [std::string (24 bytes)] [padding (4 bytes)] [function pointer (8 bytes)]

void Harl::complain(std::string level)
{
	void (Harl::*functions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "Harl does not recognize this level!" << std::endl;
}

// void Harl::complain(std::string level)
// {
// 	std::vector<std::pair<std::string, void (Harl::*)()> > functionVector;
// 	functionVector.push_back(std::make_pair("DEBUG", &Harl::debug));
// 	functionVector.push_back(std::make_pair("INFO", &Harl::info));
// 	functionVector.push_back(std::make_pair("WARNING", &Harl::warning));
// 	functionVector.push_back(std::make_pair("ERROR", &Harl::error));

// 	for (std::vector<std::pair<std::string, void (Harl::*)() > > ::iterator it = functionVector.begin();
// 		it != functionVector.end();
// 		it++)
// 	{
// 		if (it->first == level)
// 		{
// 			(this->*(it->second))();
// 			return ;
// 		}
// 	}
// 	std::cout << "Harl does not recognize this level!" << std::endl;
// }
