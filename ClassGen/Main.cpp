/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:02:06 by vheran            #+#    #+#             */
/*   Updated: 2022/08/08 15:39:40 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassGen.hpp"
#include "Sed.hpp"

std::string	askFilename( void ) {
	std::string	cmd;
	bool				ask;
	
	ask = true;
	while (ask) {
		std::cout << "Enter Filename: ";
		std::getline(std::cin, cmd);
		cmd = Sed::strReplace(cmd, " ", "_");
		if (std::cin.eof())
			exit(0);
		if (cmd.length()) {
			return (cmd);
		}
		else
			std::cout << RE << "Cannot be empty" << RC << std::endl;
	}
	return ("NewClass");
}

int	main( void ) {
	ClassGen	newClass;

	newClass.setFilename(askFilename());
	newClass.setVariables();
	if (!newClass.open_files())
		return (FAILURE);
	newClass.write_cpp();
	newClass.write_hpp();
	newClass.close_files();
	return (0);
}