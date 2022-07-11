#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact()
{
	this->_field[FirstName] = "First Name: ";
	this->_field[LastName] = "Last Name: ";
	this->_field[Nickname] = "Nickname: ";
	this->_field[PhoneNb] = "Phone Number: ";
	this->_field[Secret] = "Darkest Secret: ";
	for (int i = FirstName; i <= Secret; i++)
		this->_informations[i].clear();
}

Contact::~Contact()
{
}

void	Contact::setInformations(int idx)
{
	int		i;

	this->_idx = idx + 1;
	i = 0;
	while(i <= Secret)
	{
		std::cout << MA << std::left << std::setw(16) << this->_field[i] << RC;
		std::getline(std::cin, this->_informations[i]);
		if (!this->_informations[i].length())
			std::cout << RE << "No empty field allowed" << std::endl;
		else
			++i;
	}
}

bool	Contact::getInformations()
{
	if (this->_informations[FirstName].empty())
		return (false);
	else
	{
		std::cout << BL << std::setw(16) << "----------------"; 
		std::cout << MA << "Index #" << this->_idx << RC << std::endl;
		for (int i = FirstName; i <= Secret ; i++)
			std::cout << MA << std::left << std::setw(16) << this->_field[i] << RC << std::left << this->_informations[i] << std::endl;
		std::cout << BL << "------------------------" << RC << std::endl; 
		return (true);
	}
}

std::string	Contact::_getShortInfo(int i)
{
	std::string	ret;

	if (this->_informations[i].length() > 10)
	{
		ret = this->_informations[i].substr(0, 9);
		ret.append(".");
	}
	else
		ret = this->_informations[i];
	return (ret);
}

bool	Contact::getContact()
{
	if (this->_informations[FirstName].empty())
		return (false);
	else
	{
		if (this->_idx % 2 == 0)
			std::cout << YE;
		else
			std::cout << GR;
		std::cout << "| " << std::right << std::setw(10) << this->_idx;
		for (int i = FirstName; i <= Nickname ; i++)
			std::cout << " | " << std::right << std::setw(10) << _getShortInfo(i);
		std::cout << " |" << RC << std::endl;
		return (true);
	}
	return (true);
}