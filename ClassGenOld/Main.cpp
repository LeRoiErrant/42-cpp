/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:02:06 by vheran            #+#    #+#             */
/*   Updated: 2022/08/08 10:05:09 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassGen.hpp"


int	main(int argc, char **argv) {
	ClassGen	newClass;

	if (argc < 2)
		return(cerberror("ClassGen: error: ClassName needed", "", FAILURE));
	newClass.setFilename(argv[1]);
	if (argc > 2)
		newClass.setVariables(argc, argv);
	if (!newClass.open_files())
		return (FAILURE);
	newClass.write_cpp();
	newClass.write_hpp();
	newClass.close_files();
	return (0);
}