/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassGen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:23:38 by vheran            #+#    #+#             */
/*   Updated: 2022/07/30 15:59:23 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSGEN_HPP
# define CLASSGEN_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <filesystem>

#define FAILURE 1

int		cerberror(std::string msg, std::string arg, int errnum);
bool	cerberror(std::string msg, std::string arg, bool ret);

class ClassGen{
	private:
		std::string		_Filename;
		std::ofstream	_cpp;
		std::ofstream	_hpp;
		std::string		*_VarValue;
		std::string		*_VarType;
		int				_NbVar;
	public:
		ClassGen( void );
		ClassGen( std::string const filename );
		ClassGen( ClassGen const & src );
		~ClassGen( void );

		ClassGen	&operator=( ClassGen const & src );

		void		setFilename( std::string const filename );
		std::string	getFilename( void ) const;

		bool		setVariables( int argc, char **argv);
		bool		open_files( void );
		void		close_files( void );
		void		write_hpp( void );
		void		write_cpp( void );

};

#endif