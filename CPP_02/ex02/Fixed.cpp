/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:45:05 by vheran            #+#    #+#             */
/*   Updated: 2022/07/30 08:07:32 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_N_FBits = 8;

bool		Fixed::_Verbose = false;

bool		Fixed::_incrementBit = true;

Fixed::Fixed( void ) : _FixedPointNumber(0) {
	Fixed::_myVerbose("Default constructor called");
}

Fixed::Fixed( Fixed const & src ) {
	Fixed::_myVerbose("Copy constructor called");
	*this = src;
}

Fixed::Fixed( int const value ) {
	Fixed::_myVerbose("Int constructor called");
	this->_FixedPointNumber = value << Fixed::_N_FBits;
}

Fixed::Fixed( float const value ) {
	Fixed::_myVerbose("Float constructor called");
	this->_FixedPointNumber = roundf(value * (1 << Fixed::_N_FBits));
	//this->_FixedPointNumber = value * (1 << Fixed::_N_FBits);

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

int	Fixed::toInt( void ) const {
	return (this->_FixedPointNumber >> Fixed::_N_FBits);
}

float	Fixed::toFloat( void ) const {
	int		power = 1 << Fixed::_N_FBits;
	float	result = (float) this->_FixedPointNumber / power;
	
	return (result);
}

int	Fixed::getRawBits( void ) const {
	//Fixed::_myVerbose("getRawBits member function called");
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

std::ostream	&operator<<( std::ostream & ostream, Fixed const & src ) {
	ostream << src.toFloat();
	return (ostream);
}

bool	Fixed::operator>( Fixed const & right ) const {
	return (this->_FixedPointNumber > right.getRawBits());
}

bool	Fixed::operator<( Fixed const & right ) const {
	return (right > *this);
}

bool	Fixed::operator>=( Fixed const & right ) const {
	return (!(*this < right));
}

bool	Fixed::operator<=( Fixed const & right ) const {
	return (!(*this > right));
}

bool	Fixed::operator==( Fixed const & right ) const {
	return (this->_FixedPointNumber == right.getRawBits());
}

bool	Fixed::operator!=( Fixed const & right ) const {
	return (!(*this == right));
}

Fixed	Fixed::operator+( Fixed const & right ) const {
	Fixed	result;

	result.setRawBits(this->getRawBits() + right.getRawBits());
	return (result);
}

Fixed	Fixed::operator-( Fixed const & right ) const {
	Fixed	result;

	result.setRawBits(this->getRawBits() - right.getRawBits());
	return (result);
}

Fixed	Fixed::operator/( Fixed const & right )	const {
	Fixed	result (this->toFloat() / right.toFloat());
	return (result);
}

Fixed	Fixed::operator*( Fixed const & right ) const {
	Fixed result (this->toFloat() * right.toFloat());
	return (result);
}

Fixed	&Fixed::operator++( void ) {
	if (Fixed::_incrementBit)
		this->_FixedPointNumber++;
	else
		this->_FixedPointNumber = (this->_FixedPointNumber) + (1 << Fixed::_N_FBits);
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed	old(*this);

	if (Fixed::_incrementBit)
		this->_FixedPointNumber++;
	else
		this->_FixedPointNumber = (this->_FixedPointNumber) + (1 << Fixed::_N_FBits);
	return (old);
}

Fixed	&Fixed::operator--( void ) {
	if (Fixed::_incrementBit)
		this->_FixedPointNumber--;
	else
		this->_FixedPointNumber = (this->_FixedPointNumber) - (1 << Fixed::_N_FBits);
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed	old(*this);

	if (Fixed::_incrementBit)
		this->_FixedPointNumber--;
	else
		this->_FixedPointNumber = (this->_FixedPointNumber) - (1 << Fixed::_N_FBits);
	return (old);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	else
		return (b);
}
