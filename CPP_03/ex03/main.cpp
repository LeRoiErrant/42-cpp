#include "DiamondTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sstream>

enum mode {
	QUIT,
	SIM,
	VERSUS
};

enum bot {
	BOBBY,
	JOHN,
	COMPUTER = 0,
	PLAYER
};

enum action {
	HEAL,
	GUARD,
	HIGHFIVE,
	ATTACK,
	FORFEIT
};

void	takeTurn(DiamondTrap *bot, DiamondTrap *Opponent) {
	int	res;

	switch (std::rand() % 6) {
		case HEAL:
			bot->beRepaired((std::rand() % 15) + 1);
			break;
		case GUARD:
			bot->guardGate();
			break;
		case HIGHFIVE:
			bot->highFivesGuys();
			if (bot->getHighFived()) {
				res = (std::rand() % 6) + 1; 
				Opponent->setEnergyPoints(Opponent->getEnergyPoints() + res);
				std::cout << "[ " << std::setw(12) << std::left << *Opponent << RE << " " << std::setw(3) << std::right << Opponent->getHitPoints() << "  " << CY << std::setw(3) << std::right << Opponent->getEnergyPoints() << RC << " ]\t";
				std::cout << BL << *Opponent << " share " << *bot << "'s Glee and regain " << res << " Energy Point" << RC << std::endl;

			}
			break;
		default:
			bot->attack(Opponent->getName());
			break;
	}
}

void	Battle( void ) {
	bool 		EnergyLeft;
	bool		BotDestroyed;
	DiamondTrap	Bobby("Bobby");
	DiamondTrap	John("John");

	Bobby.whoAmI();
	John.whoAmI();
	EnergyLeft = Bobby.getEnergyPoints() or John.getEnergyPoints();
	BotDestroyed = !Bobby.getHitPoints() or !John.getHitPoints();
	while (EnergyLeft and !BotDestroyed) {
		if (std::rand() % 2 == BOBBY)
			takeTurn(&Bobby, &John);
		else
			takeTurn(&John, &Bobby);
		EnergyLeft = Bobby.getEnergyPoints() or John.getEnergyPoints();
		BotDestroyed = !Bobby.getHitPoints() or !John.getHitPoints();
	usleep(500000);
	}
	if (BotDestroyed) {
		if (!Bobby.getHitPoints())
			std::cout << MA << "WE HAVE A WINNER! " << John.getName() << " destroyed " << Bobby.getName() << "!" << RC << std::endl; 
		else
			std::cout << MA << "WE HAVE A WINNER! " << Bobby.getName() << " destroyed " << John.getName() << "!" << RC << std::endl;
	}
	else
		std::cout << MA << "IT'S A DRAW! All Bots have no Energy left!" << RC <<std::endl;
}

void	assemblyLine( void ) {
	DiamondTrap	Bot1("Diamond");
	ClapTrap	Bot2("Clap");
	ClapTrap	*test;

	Bot1.whoAmI();
	test = ClapTrap::FirstBot;
	while (test) {
		std::cout << test->getName() << " is next on assembly line" << std::endl;
		test = test->Next;
	}
}

int	askMode( void ) {
	std::string	cmd;
	bool		ask;

	ask = true;
	while (ask) {
		std::cout << MA << "Please select mode (AI / PLAYER): " << RC;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit;
		if (!cmd.compare("AI"))
			return (SIM);
		else if (!cmd.compare("PLAYER"))
			return (VERSUS);
		else if (!cmd.compare("EXIT"))
			return (QUIT);
		else
			std::cout << RE << "Invalid command" << RC << std::endl;
	}
	return (QUIT);
}

std::string	askName( void ) {
	std::string	cmd;
	std::string	scmd;
	bool		ask;
	
	ask = true;
	while (ask) {
		std::cout << "Please enter your Bot's Name: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit;
		if (!cmd.length()) {
			std::cout << RE << "Empty name not allowed" << RC << std::endl;
		}
		else if (cmd.length() > 12) {
			scmd = cmd.substr(0, 11);
			scmd.append(".");
			return (scmd);
		}
		else
			return (cmd);
	}
	return ("Unamed bot");
}

void	ComputerTurn(DiamondTrap *bot, ClapTrap *Opponent) {
	int	res;

	res = (std::rand() % 6) + 1;
	switch (std::rand() % 4) {
		case HEAL:
			bot->beRepaired((std::rand() % 10) + (std::rand() % 10) + (std::rand() % 10) + 3);
			break;
		case GUARD:
			bot->guardGate();
			break;
		case HIGHFIVE:
			bot->highFivesGuys();
			if (bot->getHighFived()) {
				res = (std::rand() % 6) + 1; 
				Opponent->setEnergyPoints(Opponent->getEnergyPoints() + res);
				std::cout << "[ " << std::setw(12) << std::left << *Opponent << RE << " " << std::setw(3) << std::right << Opponent->getHitPoints() << "  " << CY << std::setw(3) << std::right << Opponent->getEnergyPoints() << RC << " ]\t";
				std::cout << BL << *Opponent << " share " << *bot << "'s Glee and regain " << res << " Energy Point" << RC << std::endl;

			}
			break;
		default:
			if ( bot->getHitPoints() < (bot->getInitialHP() / 2)) {
				if (std::rand() % 100 < 50)
					bot->beRepaired((std::rand() % 10) + (std::rand() % 10) + (std::rand() % 10) + 3);
				else {
					bot->setAttackDamage((std::rand() % 15) + 15);
					bot->attack(Opponent->getName());
				}
			}
			else {
				bot->setAttackDamage((std::rand() % 15) + 15);
				bot->attack(Opponent->getName());
			}
			break;
	}
}

int	PlayerAction( std::string *PlayerActions ) {
	std::string	cmd;
	bool		ask;

	ask = true;
	while (ask) {
		std::cout << MA << "Please select action ( ATTACK / GUARD / REPAIR ): " << RC;
		std::getline(std::cin, cmd);
		for (int i = HEAL; i <= FORFEIT; i++) {
			if (!cmd.compare(PlayerActions[i]))
				return (i);
		}
		std::cout << RE << "Invalid command" << RC << std::endl;
	}
	return (ATTACK);
}

void	PlayerTurn(DiamondTrap *bot, ClapTrap *Opponent, std::string *PlayerActions) {
	int	res;

	res = (std::rand() % 6) + 1;
	switch (PlayerAction(PlayerActions)) {
		case HEAL:
			bot->beRepaired((std::rand() % 10) + (std::rand() % 10) + (std::rand() % 10));
			break;
		case GUARD:
			bot->guardGate();
			break;
		case HIGHFIVE:
			bot->highFivesGuys();
			if (bot->getHighFived()) {
				res = (std::rand() % 6) + 1; 
				Opponent->setEnergyPoints(Opponent->getEnergyPoints() + res);
				std::cout << "[ " << std::setw(12) << std::left << *Opponent << RE << " " << std::setw(3) << std::right << Opponent->getHitPoints() << "  " << CY << std::setw(3) << std::right << Opponent->getEnergyPoints() << RC << " ]\t";
				std::cout << BL << *Opponent << " share " << *bot << "'s Glee and regain " << res << " Energy Point" << RC << std::endl;

			}
			break;
		case FORFEIT:
			bot->setHitPoints(0);
			std::cout << "[ " << std::setw(12) << std::left << *bot << RE << " " << std::setw(3) << std::right << bot->getHitPoints() << "  " << CY << std::setw(3) << std::right << bot->getEnergyPoints() << RC << " ]\t";
			std::cout << RE << "Self-Destruct Engaged!" << RC << std::endl;
			break;
		default:
			bot->setAttackDamage((std::rand() % 15) + 15);
			bot->attack(Opponent->getName());
			break;
	}
}

void	versusBattle( std::string *PlayerActions ) {
	DiamondTrap	Computer("J0CK");
	DiamondTrap	Player(askName());
	bool		EnergyLeft;
	bool		BotDestroyed;
	int			Turn;

	Computer.whoAmI();
	Player.whoAmI();
	EnergyLeft = Player.getEnergyPoints() or Computer.getEnergyPoints();
	BotDestroyed = !Player.getHitPoints() or !Computer.getHitPoints();
	Turn = (std::rand() % 2);
	while (EnergyLeft and !BotDestroyed) {
		if (Turn == COMPUTER) {
			ComputerTurn(&Computer, &Player);
			Turn = PLAYER;
		}
		else {
			PlayerTurn(&Player, &Computer, PlayerActions);
			Turn = COMPUTER;
		}
		EnergyLeft = Player.getEnergyPoints() or Computer.getEnergyPoints();
		BotDestroyed = !Player.getHitPoints() or !Computer.getHitPoints();
	usleep(500000);
	}
	if (BotDestroyed) {
		if (!Player.getHitPoints())
			std::cout << MA << "WE HAVE A WINNER! " << Computer.getName() << " destroyed " << Player.getName() << "!" << RC << std::endl; 
		else
			std::cout << MA << "WE HAVE A WINNER! " << Player.getName() << " destroyed " << Computer.getName() << "!" << RC << std::endl;
	}
	else
		std::cout << MA << "IT'S A DRAW! Both Bots have no Energy left!" << RC <<std::endl;
}

void	askVerbose( void ) {
	std::string	cmd;
	bool		ask;
	
	ask = true;
	while (ask) {
		std::cout << "Verbose activated ( y / N ) ? ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit;
		if (!cmd.compare("y")) {
			ClapTrap::setVerbose(true);
			ask = false;
		}
		else if (!cmd.compare("N")) {
			ClapTrap::setVerbose(false);
			ask = false;
		}
		else
			std::cout << RE << "Invalid command" << RC << std::endl;
	}
}

bool	askAssemblyLine( void ) {
	std::string	cmd;
	bool		ask;
	
	ask = true;
	while (ask) {
		std::cout << "Check Assembly line ( y / N ) ? ";
		std::getline(std::cin, cmd);
		if (!cmd.compare("y"))
			return (true);
		else if (!cmd.compare("N"))
			return (false);
		else
			std::cout << RE << "Invalid command" << RC << std::endl;
	}
	return (false);
}

int	main( void ) {
	std::string	PlayerActions[5];
	if (askAssemblyLine())
		assemblyLine();
	std::srand(time(NULL));
	switch (askMode()) {
		case SIM:
			askVerbose();
			Battle();
			break;
		case VERSUS:
			askVerbose();
			PlayerActions[HEAL] = "REPAIR";
			PlayerActions[GUARD] = "GUARD";
			PlayerActions[HIGHFIVE] = "HIGHFIVE";
			PlayerActions[ATTACK] = "ATTACK";
			PlayerActions[FORFEIT] = "FORFEIT";
			versusBattle(PlayerActions);
			break;
		default:
			std::cout << "Leaving the Arena" << std::endl;
			break;
	}
	return 0;
}