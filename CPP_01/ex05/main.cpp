/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:10:07 by vheran            #+#    #+#             */
/*   Updated: 2022/07/25 18:17:09 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

enum _lvl{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

int	main(int argc, char **argv)
{
	Harl		Harl;

	if (argc == 2)
	{
		std::string	arg(argv[1]);
		for (size_t i = 0; i < arg.length(); i++)
			arg[i] = std::toupper(arg[i]);
		Harl.complain(arg);
	}
	else if (argc == 1)
	{
		std::srand(time(NULL));
		Harl.complain(Harl.get_anger_lvl(std::rand() % 4));
	}
	else
		std::cout << "error: bad arguments" << std::endl;
	return (0);
}