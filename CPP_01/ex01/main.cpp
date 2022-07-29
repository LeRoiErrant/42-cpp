/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:54:46 by vheran            #+#    #+#             */
/*   Updated: 2022/07/29 14:22:34 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(int argc, char ** argv)
{
	Zombie	*Horde;
	if (argc != 3)
	{
		std::cout << "error: please inform how many zombies then their name" << std::endl;
		return (1);
	}
	Horde = zombieHorde(std::atoi(argv[1]), argv[2]);
	Zombie::checkHorde(Horde);
	delete [] Horde;
	std::cout << "Leaving the Horde" << std::endl;
	return (0);
}