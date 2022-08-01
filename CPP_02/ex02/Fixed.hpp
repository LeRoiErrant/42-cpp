/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:30:53 by vheran            #+#    #+#             */
/*   Updated: 2022/07/30 23:24:15 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	private:
		static const int	_N_FBits;
		int					_FixedPointNumber;

		static bool			_Verbose;
		static bool			_incrementBit;
		static void			_myVerbose(std::string msg);

	public:
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed( int const value );
		Fixed( float const value );
		~Fixed( void );

		Fixed	&operator=( Fixed const & src );
		bool	operator>( Fixed const & right ) const;
		bool	operator<( Fixed const & right ) const;
		bool	operator>=( Fixed const & right ) const;
		bool	operator<=( Fixed const & right ) const;
		bool	operator==( Fixed const & right ) const;
		bool	operator!=( Fixed const & right ) const;
		Fixed	operator+( Fixed const & right ) const;
		Fixed	operator-( Fixed const & right ) const;
		Fixed	operator*( Fixed const & right ) const;
		Fixed	operator/( Fixed const & right ) const;
		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);

		static bool	getVerbose( void );
		static void	setVerbose( bool value);
};

std::ostream	&operator<<( std::ostream & ostream, Fixed const & src );

#endif