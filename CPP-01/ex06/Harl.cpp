/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:00:21 by jteissie          #+#    #+#             */
/*   Updated: 2024/08/22 15:17:15 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love working in Made, Made has Moulinette the cat, Made is awesome!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Made is crawling with centipedes, I cannot believe Made is overrun with these annoying pesky bugs!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve a workspace free of bugs, I have been working on my minishell for 2 years and never had to suffer from such insects!" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, that is it, I am blackholing!" << std::endl;
}

//pair : [std::string (24 bytes)] [padding (4 bytes)] [function pointer (8 bytes)]

void Harl::complain(filter_level level)
{
	std::vector<std::pair<filter_level, void (Harl::*) ()> > functionVector;
	functionVector.push_back(std::make_pair(DEBUG, &Harl::debug));
	functionVector.push_back(std::make_pair(INFO, &Harl::info));
	functionVector.push_back(std::make_pair(WARNING, &Harl::warning));
	functionVector.push_back(std::make_pair(ERROR, &Harl::error));

	std::vector<std::pair<filter_level, void (Harl::*)() > > ::iterator it;
	for (int i = 0; i < 1; i++)
	{
		for (it = functionVector.begin(); it != functionVector.end(); it++)
		{
			if (it->first >= level)
			{
				(this->*(it->second))();
				std::cout << std::endl;
			}
		}
	}
}

void Harl::filter(std::string level)
{
	std::map<std::string, filter_level > index;
	index["DEFAULT"] = DEFAULT;
	index["DEBUG"] = DEBUG;
	index["INFO"] = INFO;
	index["WARNING"] = WARNING;
	index["ERROR"] = ERROR;

	switch (index[level]) {
		case DEBUG:
			complain(DEBUG);
			break;
		case INFO:
			complain(INFO);
			break;
		case WARNING:
			complain(WARNING);
			break;
		case ERROR:
			complain(ERROR);
			break;
		case DEFAULT:
			std::cout << "[Incomprehensible ramblings about minishell, probably...]" << std::endl;
			break ;
		}
}
