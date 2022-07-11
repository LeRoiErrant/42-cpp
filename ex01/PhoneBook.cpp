#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _idx(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact()
{
	int	idx;

	idx = this->_idx % 8;
	std::cout << BL << std::setw(16) << "----------------";
	std::cout << MA << "Index #" << idx + 1 << RC << std::endl;
	this->_contacts[idx].setInformations(idx);
	std::cout << BL << "------------------------" << RC << std::endl; 
	if (this->_idx < 8)
		std::cout << GR << "Contact #" << idx + 1 << " succesfully added!" << RC << std::endl;
	else
		std::cout << GR << "Contact #" << idx + 1 << " succesfully remplaced!" << RC << std::endl;
	std::cout << BL << "------------------------" << RC << std::endl; 
	this->_idx++;
}

void	PhoneBook::to_know_more()
{
	std::string			cmd;
	std::stringstream	ss;
	int					idx;

	std::cout << MA << "Enter a contact index to know more, or 9 to exit" << RC << std::endl;
	std::cout << GR << "> " << RC;
	cmd.clear();
	idx = 0;
	std::getline(std::cin, cmd);
	ss << cmd;
	ss >> idx;
	if (idx < 1 or 9 < idx or (idx != 9 and this->_contacts[idx - 1].getInformations() == false))
	{
		std::cout << RE << "Invalid index" << RC << std::endl;
		this->to_know_more();
	}
}

void	PhoneBook::display_contacts()
{
	bool		loop;


	loop = true;
	if (!this->_idx)
		std::cout << RE << "No contact to display" << RC << std::endl;
	else
	{
		std::cout << MA << "| " << std::right << std::setw(10);
		std::cout << "index" << " | ";
		std::cout << std::right << std::setw(10) << "first name" << " | ";
		std::cout << std::right << std::setw(10) <<  "last name" << " | ";
		std::cout << std::right << std::setw(10) <<  "nickname" << " |" << RC << std::endl;
		for (int i = 0 ; i < 8 && loop; i++)
		{
			if (!this->_contacts[i].getContact())
				loop = false;
		}
		this->to_know_more();
	}
}