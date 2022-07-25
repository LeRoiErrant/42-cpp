/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:43:34 by vheran            #+#    #+#             */
/*   Updated: 2022/07/25 18:12:29 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\n";
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
