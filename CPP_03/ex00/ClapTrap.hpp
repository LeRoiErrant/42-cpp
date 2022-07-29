/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:22:26 by vheran            #+#    #+#             */
/*   Updated: 2022/07/29 13:15:21 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

	private:
		std::string		_Name;
		unsigned int	_HitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_AttackDamage;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap( void );

		ClapTrap	&operator=(ClapTrap const & rhs);

		std::string		getName( void );
		unsigned int	getHitPoints( void );
		unsigned int	getEnergyPoints( void );
		unsigned int	getAttackDamage( void );

		void			setName(std::string name);
		void			setHitpoints(unsigned int hp);
		void			setEnergyPoints(unsigned int ep);
		void			setAttackDamage(unsigned int dpa);

};

#endif