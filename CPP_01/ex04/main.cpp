/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:11:25 by vheran            #+#    #+#             */
/*   Updated: 2022/07/29 14:09:17 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	cerberror(std::string msg, char *arg, int errnum)
{
	if (!msg.empty())
		std::cerr << msg;
	if (arg)
		std::cerr << arg;
	std::cerr << std::endl;
	return (errnum);
}

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;

	if (argc != 4)
		return (cerberror("Bad arguments: filestream str1 str2", 0, FAILURE));
	else
	{
		try
		{
			Sed::replace(argv[1], argv[2], argv[3]);	
		}
		catch(const std::string &e)
		{
			std::cerr << e << std::endl;
		}
		
	}
	return (SUCCESS);
}