#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		void	setInformations(int idx);
		bool	getInformations();
		bool	getContact();

	private:
		int			_idx;
		std::string	_field[5];
		std::string	_informations[5];
		
		enum Fields {
			FirstName = 0,
			LastName,
			Nickname,
			PhoneNb,
			Secret
		};

		std::string	_getShortInfo(int i);
};

#endif