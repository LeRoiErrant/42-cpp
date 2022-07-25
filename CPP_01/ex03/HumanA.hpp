/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:12:10 by vheran            #+#    #+#             */
/*   Updated: 2022/07/21 12:11:45 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
	std::string const & _name;
	Weapon&	_weapon;

	public:
	HumanA(std::string const & name, Weapon &weapon);
	~HumanA();

	void	attack();
};

#endif