#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	bool		run;
	std::string	cmd;

	run = true;
	while (run)
	{
		std::cout << MA << "Please enter your command (ADD, SEARCH, EXIT)" << RC << std::endl;
		std::cout << GR << "> " << RC;
		std::getline(std::cin, cmd);
		if (!cmd.compare("EXIT"))
		{
			std::cout << MA << " # So long and thanks for all the fish !" << std::endl;
			run = false;
		}
		else if (!cmd.compare("ADD"))
			pb.add_contact();
		else if (!cmd.compare("SEARCH"))
			pb.display_contacts();
		else
			std::cout << RE << "Invalid command" << RC << std::endl;
	}
	return (0);
}