/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:08:53 by vheran            #+#    #+#             */
/*   Updated: 2022/07/20 08:42:32 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>

class Weapon
{
	private:
	std::string	_type;

	public:
	Weapon();
	Weapon(std::string const & type);
	~Weapon();

	std::string const &	getType(void);
	void				setType(std::string const & type);
};

#endif