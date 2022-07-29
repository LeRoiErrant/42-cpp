/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:18:12 by vheran            #+#    #+#             */
/*   Updated: 2022/07/29 13:24:27 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	Zombie::_total = 0;

Zombie::Zombie() : _name("")
{
	Zombie::_total += 1;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " died (again)..." << std::endl;
	Zombie::_total -= 1;
}

void	Zombie::announce(void)
{
	if (!this->_name.empty())
		std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::checkHorde(Zombie *Horde)
{
	for (int i = 0; i < Zombie::_total; i++)
	{
		std::cout << i << ". ";
		Horde[i].announce();
	}
}