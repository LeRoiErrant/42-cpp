/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:36:11 by vheran            #+#    #+#             */
/*   Updated: 2022/08/08 10:12:04 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SED_HPP
# define SED_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

# define BLINK "\033[1;5m"
# define BOLD "\033[1m"
# define ITAL "\033[3m"
# define UNDRL "\033[4m"
# define HDDN "\033[8m"
# define GR "\033[32;1m"
# define RE "\033[31;1m"
# define DR "\033[31;1;2m"
# define YE "\033[33;1m"
# define CY "\033[36;1m"
# define LG "\033[37;1;3m"
# define DG "\033[90;1;3m"
# define DGB "\033[90;1m"
# define LB "\033[94;1m"
# define WH "\033[97m"
# define MA "\001\033[1;95m\002"
# define BL "\001\033[1;94m\002"
# define RC "\033[0m"

# define FAILURE 1
# define SUCCESS 0

class Sed
{
	private:

	public:
		Sed();
		~Sed();

		static void	replace(std::string const &filename, std::string const &search, std::string const &replace);
		static std::string	strReplace(std::string const &line, std::string const &search, std::string const &replace);
		static std::string	strToUpper(std::string const &line);
};

#endif