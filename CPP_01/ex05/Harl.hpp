/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:20:17 by vheran            #+#    #+#             */
/*   Updated: 2022/07/25 16:40:54 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

# define true 0

class Harl
{
	private:
		enum _lvl {
			DEBUG,
			INFO,
			WARNING,
			ERROR
		};

		void	(Harl::*complaint[4])(void);

		std::string	angerLVL[4];

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
		std::string	get_anger_lvl(int lvl);
};

#endif