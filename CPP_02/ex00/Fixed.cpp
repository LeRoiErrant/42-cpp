/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:45:05 by vheran            #+#    #+#             */
/*   Updated: 2022/07/27 14:18:13 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_N_FBits = 8;

bool		Fixed::_Verbose = true;

Fixed::Fixed( void ) : _FixedPointNumber(0) {
	Fixed::_myVerbose("Default constructor called");
}

Fixed::Fixed( Fixed const & src ) {
	Fixed::_myVerbose("Copy constructor called");
	*this = src;
}

Fixed::~Fixed( void ) {
	Fixed::_myVerbose("Destructor called");
}

Fixed	&Fixed::operator=(Fixed const &src) {
	Fixed::_myVerbose("Copy assignement operator called");
	if (this != &src)
		this->_FixedPointNumber = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const {
	Fixed::_myVerbose("getRawBits member function called");
	return (this->_FixedPointNumber);
}

void	Fixed::setRawBits( int const raw ) {
	Fixed::_myVerbose("setRawBits member function called");
	this->_FixedPointNumber = raw;
}

bool	Fixed::getVerbose( void ) {
	return (Fixed::_Verbose);
}

void	Fixed::setVerbose( bool value ) {
	Fixed::_Verbose = value;
}

void	Fixed::_myVerbose(std::string msg) {
	if (Fixed::_Verbose)
		std::cout << msg << std::endl;
}
