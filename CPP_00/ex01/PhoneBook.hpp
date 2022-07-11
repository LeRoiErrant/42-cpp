#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

# define GR "\033[32;1m"
# define RE "\033[31;1m"
# define YE "\033[33;1m"
# define CY "\033[36;1m"
# define MA "\001\033[1;95m\002"
# define BL "\001\033[1;94m\002"
# define RC "\033[0m"

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact();
		void	display_contacts();
		void	to_know_more();

	private:
		int		_idx;
		Contact	_contacts[8];
};

#endif