/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:43:34 by vheran            #+#    #+#             */
/*   Updated: 2022/07/25 18:18:27 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "\n[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "\n[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "\n[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "\n[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string lvl)
{
	for (int i = DEBUG; i <= ERROR; i++)
	{
		if (lvl.compare(this->angerLVL[i]) == true)
		{
			(this->*complaint[i])();
			return ;
		}
	}
	std::cout << "[Harl mumble incomprehensibly]" << std::endl;
}

std::string	Harl::get_anger_lvl(int lvl)
{
	return (this->angerLVL[lvl]);
}

int	Harl::get_lvl_from_string(std::string lvl)
{
	for (int i = DEBUG; i <= ERROR; i++)
		if (lvl.compare(this->angerLVL[i]) == true)
			return (i);
	return (NIHIL);
}

void	Harl::Harl_filter(std::string lvl)
{
	int	ilvl(this->get_lvl_from_string(lvl));

	while (ilvl < END)
	{
		switch (ilvl)
		{
			case DEBUG:
				(this->*complaint[DEBUG])();
				ilvl++;
				break;
			case INFO:
				(this->*complaint[INFO])();
				ilvl++;
				break;
			case WARNING:
				(this->*complaint[WARNING])();
				ilvl++;
				break;
			case ERROR:
				(this->*complaint[ERROR])();
				std::cout << std::endl;
				ilvl = END;
				break;
			default:
				std::cout << "\n[ Probably complaining about insignificant problems ]\n" << std::endl;
				ilvl = END;
				break;
		}
	}
}

Harl::Harl(void)
{
	this->complaint[DEBUG] = &Harl::debug;
	this->complaint[INFO] = &Harl::info;
	this->complaint[WARNING] =	&Harl::warning;
	this->complaint[ERROR] = &Harl::error;

	this->angerLVL[DEBUG] = "DEBUG";
	this->angerLVL[INFO] = "INFO";
	this->angerLVL[WARNING] = "WARNING";
	this->angerLVL[ERROR] = "ERROR";
}

Harl::~Harl(void)
{
}
