/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:12:05 by vheran            #+#    #+#             */
/*   Updated: 2022/07/21 12:26:25 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
	std::string const & _name;
	Weapon*	_weapon;

	public:
	HumanB(std::string const & name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &weapon);
	void	unsetWeapon();
};

#endif