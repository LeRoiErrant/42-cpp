/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:30:53 by vheran            #+#    #+#             */
/*   Updated: 2022/07/27 14:12:14 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		static const int	_N_FBits;
		int					_FixedPointNumber;

		static bool			_Verbose;
		static void			_myVerbose(std::string msg);

	public:
		Fixed( void );
		Fixed( Fixed const & src);
		~Fixed( void );

		Fixed	&operator=( Fixed const & src );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		static bool	getVerbose( void );
		static void	setVerbose( bool value);
};

#endif