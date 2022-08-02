/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:22:26 by vheran            #+#    #+#             */
/*   Updated: 2022/08/02 09:17:25 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <sstream>
# include <iomanip>

# define GR "\033[32;1m"
# define RE "\033[31;1m"
# define YE "\033[33;1m"
# define CY "\033[36;1m"
# define MA "\001\033[1;95m\002"
# define BL "\001\033[1;94m\002"
# define RC "\033[0m"

# define HP 10
# define EP 10
# define DPA 0

class ClapTrap {

	private:

	protected:
		std::string			_Name;	
		unsigned int		_HitPoints;
		unsigned int		_InitialHP;
		unsigned int		_EnergyPoints;
		unsigned int		_AttackDamage;

		static bool			_Verbose;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap( void );

		ClapTrap	&operator=(ClapTrap const & rhs);

		static ClapTrap		*FirstBot;
		static ClapTrap		*LastBot;
		ClapTrap			*Previous;
		ClapTrap			*Next;

		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getInitialHP( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;

		void			setName(std::string const name);
		void			setHitPoints(unsigned int const hp);
		void			setInitialHP( unsigned int const value );
		void			setEnergyPoints(unsigned int const ep);
		void			setAttackDamage(unsigned int const dpa);
		static void		setVerbose(bool const value);

		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

std::ostream	&operator<<( std::ostream & ostream, ClapTrap const & src );

#endif