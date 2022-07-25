/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:58:47 by vheran            #+#    #+#             */
/*   Updated: 2022/07/20 08:04:16 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string 	str("HI THIS IS BRAIN");
	std::string*	ptr = &str;
	std::string&	ref = str;
	std::cout << "Memory address:" << std::endl;
	std::cout << "STR: " << &str << std::endl;
	std::cout << "PTR: " << ptr << std::endl;
	std::cout << "REF: " << &ref << std::endl;
	std::cout << "Value:" << std::endl;
	std::cout << "STR: " << str << std::endl;
	std::cout << "PTR: " << *ptr << std::endl;
	std::cout << "REF: " << str << std::endl;
	return (0);
}