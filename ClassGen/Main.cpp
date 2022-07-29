/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:02:06 by vheran            #+#    #+#             */
/*   Updated: 2022/07/29 14:25:05 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassGen.hpp"

#define FAILURE 1

int	cerberror(std::string msg, std::string arg, int errnum) {
	if (!msg.empty())
		std::cerr << msg;
	if (!arg.empty())
		std::cerr << arg;
	std::cerr << std::endl;
	return (errnum);
}

bool	open_files(std::string const & filename) {
	std::ofstream	cpp;
	std::ofstream	hpp;
	std::string		c_outfile(filename);
	std::string		h_outfile(filename);
	
	c_outfile.append(".cpp");
	cpp.open(c_outfile.data(), std::ios::trunc);
	if (!cpp.is_open())
		return (cerberror("can't open: ", c_outfile, false));
	h_outfile.append(".hpp");
	hpp.open(h_outfile.data(), std::ios::trunc);
	if (!hpp.is_open())
		return (cerberror("can't open: ", h_outfile, false));
	return (true);
}

int	main(int argc, char **argv) {
	//int				i = 1;
	
	(void) argc;
	if (!open_files(argv[1]))
		return (FAILURE);
	return (0);
}