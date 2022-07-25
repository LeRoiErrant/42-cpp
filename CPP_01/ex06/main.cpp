/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:10:07 by vheran            #+#    #+#             */
/*   Updated: 2022/07/25 17:48:37 by vheran           ###   ########.fr       */
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

	if (argc != 2)
	{
		std::cout << "error: bad arguments" << std::endl;
		return (1);
	}		
	else
	{
		std::string arg(argv[1]);
		for (size_t i = 0; i < arg.length(); i++)
			arg[i] = std::toupper(arg[i]);
		Harl.Harl_filter(arg);
	}
	return (0);
}