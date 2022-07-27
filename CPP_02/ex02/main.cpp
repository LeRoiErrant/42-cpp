/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:09:56 by vheran            #+#    #+#             */
/*   Updated: 2022/07/27 15:31:18 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	float	t_a = 0.5f;
	int		t_b = 5;
	float	t_c = 5.0f;
	float	t_d = 42.3f;
	Fixed	a( t_a );
	Fixed	b( t_b );
	Fixed	c( t_c );
	Fixed	d( t_d );
	Fixed	e( c );
	int		t = 1;
	
	std::cout << "-----------A: " << t_a << "--------------" << std::endl;
	std::cout << "Raw bits: " << a.getRawBits() << std::endl;
	std::cout << "Operator: " << a << std::endl;
	std::cout << "Int: " << a.toInt() << std::endl;
	std::cout << "Float: " << a.toFloat() << std::endl;
	std::cout << "\n-----------B: " << t_b << "--------------" << std::endl;
	std::cout << "Raw bits: " << b.getRawBits() << std::endl;
	std::cout << "Operator: " << b << std::endl;
	std::cout << "Int: " << b.toInt() << std::endl;
	std::cout << "Float: " << b.toFloat() << std::endl;
	std::cout << "\n-----------C: " << t_c << "--------------" << std::endl;
	std::cout << "Raw bits: " << c.getRawBits() << std::endl;
	std::cout << "Operator: " << c << std::endl;
	std::cout << "Int: " << c.toInt() << std::endl;
	std::cout << "Float: " << c.toFloat() << std::endl;
	std::cout << "\n-----------D: " << t_d << "--------------" << std::endl;
	std::cout << "Raw bits: " << d.getRawBits() << std::endl;
	std::cout << "Operator: " << d << std::endl;
	std::cout << "Int: " << d.toInt() << std::endl;
	std::cout << "Float: " << d.toFloat() << std::endl;

	std::cout << "\n\n--------Others tests--------" << std::endl;
	std::cout << "Etalon (true): " << (t == 1) << std::endl;
	std::cout << "Etalon (false): " << (t == 2) << std::endl;
	std::cout << "Test: " << (b == c) << std::endl;
	std::cout << "\n\n----------------------------\n" << std::endl;

	return 0;
}