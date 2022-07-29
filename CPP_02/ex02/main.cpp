/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:09:56 by vheran            #+#    #+#             */
/*   Updated: 2022/07/29 11:43:09 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << b << " / 3 = " << b / 3 << std::endl;
	std::cout << b << " + 3 = " << b + 3 << std::endl;
	std::cout << b << " - 3 = " << b - 3 << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	return 0;
}

/*int	main( void ) {
	float	t_a = 0.5f;
	int		t_b = 5;
	float	t_c = 5.0f;
	float	t_d = 42.3f;
	int		t = 1;
	Fixed	e;
	
	std::cout << "-----------A: " << t_a << "--------------" << std::endl;
	Fixed	a( t_a );
	std::cout << "Raw bits: " << a.getRawBits() << std::endl;
	std::cout << "Operator: " << a << std::endl;
	std::cout << "Int: " << a.toInt() << std::endl;
	std::cout << "Float: " << a.toFloat() << std::endl;
	std::cout << "\n-----------B: " << t_b << "--------------" << std::endl;
	Fixed	b( t_b );
	std::cout << "Raw bits: " << b.getRawBits() << std::endl;
	std::cout << "Operator: " << b << std::endl;
	std::cout << "Int: " << b.toInt() << std::endl;
	std::cout << "Float: " << b.toFloat() << std::endl;
	std::cout << "\n-----------C: " << t_c << "--------------" << std::endl;
	Fixed	c( t_c );
	std::cout << "Raw bits: " << c.getRawBits() << std::endl;
	std::cout << "Operator: " << c << std::endl;
	std::cout << "Int: " << c.toInt() << std::endl;
	std::cout << "Float: " << c.toFloat() << std::endl;
	std::cout << "\n-----------D: " << t_d << "--------------" << std::endl;
	Fixed	d( t_d );
	std::cout << "Raw bits: " << d.getRawBits() << std::endl;
	std::cout << "Operator: " << d << std::endl;
	std::cout << "Int: " << d.toInt() << std::endl;
	std::cout << "Float: " << d.toFloat() << std::endl;

	std::cout << "\n\n--------Others tests--------" << std::endl;
	std::cout << "Etalon (true): " << (t == 1) << std::endl;
	std::cout << "Etalon (false): " << (t == 2) << std::endl;
	std::cout << "Test: " << b << ">" << c << ": " << (b > c) << std::endl;
	std::cout << "Test: " << b << "==" << c << ": " << (b == c) << std::endl;
	std::cout << "Test: " << b << "!=" << c << ": " << (b != c) << std::endl;
	std::cout << "Test: " << b << "!=" << a << ": " << (b != a) << std::endl;
	std::cout << "Test: " << b << ">" << a << ": " << (b > a) << std::endl;
	std::cout << "Test: " << b << "<" << a << ": " << (b < a) << std::endl;
	std::cout << "Test: " << b << ">=" << a << ": " << (b >= a) << std::endl;
	std::cout << "Test: " << b << "<=" << a << ": " << (b <= a) << std::endl;
	std::cout << "Test: " << a << ">=" << b << ": " << (a >= b) << std::endl;
	std::cout << "Test: " << a << "<=" << b << ": " << (a <= b) << std::endl;
	std::cout << "Test: " << b << ">=" << c << ": " << (b >= c) << std::endl;
	std::cout << "Test: " << b << "<=" << c << ": " << (b <= c) << std::endl;
	std::cout << "Add: " << b << " + " << c << ": ";
	e = b + c;
	std:: cout 	<< e << std::endl;
	std::cout << "Increment test (++b): " << ++b << ": " << b << std::endl;
	std::cout << "Increment test (b++): " << b++ << ": " << b << std::endl;
std::cout << "Increment test (--b): " << --b << ": " << b << std::endl;
	std::cout << "Increment test (b--): " << b-- << ": " << b << std::endl;
	std::cout << "\n----------------------------\n" << std::endl;
	return 0;
}*/