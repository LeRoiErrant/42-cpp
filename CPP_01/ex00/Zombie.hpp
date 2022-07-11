/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:47:31 by vheran            #+#    #+#             */
/*   Updated: 2022/07/11 17:57:52 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie( void );

	private:
		std::string	_name;
};

Zombie* newZombie( std::string name);
void	randomChump( std::string name);

#endif
