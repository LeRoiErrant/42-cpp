/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:11:14 by vheran            #+#    #+#             */
/*   Updated: 2022/07/20 08:39:03 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("")
{	
}

Weapon::Weapon(std::string const & type) : _type(type)
{
}

Weapon::~Weapon()
{
}

std::string const & Weapon::getType()
{
	return this->_type;
}

void	Weapon::setType(std::string const & type)
{
	this->_type = type;
}