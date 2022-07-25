/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:47:31 by vheran            #+#    #+#             */
/*   Updated: 2022/07/19 13:57:20 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
class Zombie {
	
	private:
		std::string	_name;
		static int	_total;

	public:
		Zombie( void );
		~Zombie( void );
		void	announce(void);
		void	setName(std::string name);
		static void	checkHorde(Zombie *Horde);

};

Zombie* zombieHorde(int N, std::string name);

#endif
