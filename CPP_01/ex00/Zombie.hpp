/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:47:31 by vheran            #+#    #+#             */
/*   Updated: 2022/07/19 08:43:06 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
class Zombie {
	public:
		Zombie(std::string name);
		~Zombie( void );
		void	announce(void);

	private:
		std::string	_name;
};

Zombie* newZombie( std::string name);
void	randomChump( std::string name);

#endif
