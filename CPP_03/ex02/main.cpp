#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	HEAVY,
	QUICK,
	COMPUTER = 0,
	PLAYER,
	SCAV = 0,
	FRAG
};

enum action {
	HEAL,
	GUARD,
	HIGHFIVE = 1,
	ATTACK,
	FORFEIT
};

void	takeTurn(FragTrap *bot, ScavTrap *Opponent) {
	int	res;

	switch (std::rand() % 6) {
		case HEAL:
			bot->beRepaired((std::rand() % 15) + 1);
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

void	takeTurn(ScavTrap *bot, FragTrap *Opponent) {
	switch (std::rand() % 4) {
		case HEAL:
			bot->beRepaired((std::rand() % 15) + 1);
			break;
		case GUARD:
			bot->guardGate();
			break;
		default:
			bot->attack(Opponent->getName());
			break;
	}
}

void	Battle( void ) {
	bool 		EnergyLeft;
	bool		BotDestroyed;
	ScavTrap	Scav("GU4RD14N");
	FragTrap	Frag("J0CK");

	
	EnergyLeft = Scav.getEnergyPoints() or Frag.getEnergyPoints();
	BotDestroyed = !Scav.getHitPoints() or !Frag.getHitPoints();
	while (EnergyLeft and !BotDestroyed) {
		if (std::rand() % 2 == SCAV)
			takeTurn(&Scav, &Frag);
		else
			takeTurn(&Frag, &Scav);
		EnergyLeft = Scav.getEnergyPoints() or Frag.getEnergyPoints();
		BotDestroyed = !Scav.getHitPoints() or !Frag.getHitPoints();
	usleep(500000);
	}
	if (BotDestroyed) {
		if (!Scav.getHitPoints())
			std::cout << MA << "WE HAVE A WINNER! " << Frag.getName() << " destroyed " << Scav.getName() << "!" << RC << std::endl; 
		else
			std::cout << MA << "WE HAVE A WINNER! " << Scav.getName() << " destroyed " << Frag.getName() << "!" << RC << std::endl;
	}
	else
		std::cout << MA << "IT'S A DRAW! All Bots have no Energy left!" << RC <<std::endl;
}

void	assemblyLine( void ) {
	ClapTrap	Bot1("Bot1");
	ScavTrap	Bot2("Bot2");
	ClapTrap	Bot3("Bot3");
	FragTrap	Bot4("Bot4");
	ClapTrap	Clone1(Bot1);
	ScavTrap	Clone2(Bot2);
	FragTrap	Clone3(Bot4);
	ClapTrap	Unamed;
	ClapTrap	Unamed2;
	ClapTrap	*test;

	Unamed = Bot2;
	Unamed2 = Bot4;
	test = ClapTrap::FirstBot;
	while (test) {
		std::cout << *test << " is next on assembly line" << std::endl;
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

void	ComputerTurn(FragTrap *bot, ClapTrap *Opponent) {
	int	res;

	res = (std::rand() % 6) + 1;
	switch (std::rand() % 4) {
		case HEAL:
			bot->beRepaired((std::rand() % 10) + (std::rand() % 10) + (std::rand() % 10) + 3);
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

int	PlayerAction( void ) {
	std::string	cmd;
	bool		ask;

	ask = true;
	while (ask) {
		std::cout << MA << "Please select action ( ATTACK / GUARD / REPAIR / HIGHFIVE ): " << RC;
		std::getline(std::cin, cmd);
		if (!cmd.compare("ATTACK"))
			return (ATTACK);
		else if (!cmd.compare("GUARD"))
			return (GUARD);
		else if (!cmd.compare("REPAIR"))
			return (HEAL);
		else if (!cmd.compare("FORFEIT"))
			return (FORFEIT);
		else
			std::cout << RE << "Invalid command" << RC << std::endl;
	}
	return (ATTACK);
}

void	PlayerTurn(ScavTrap *bot, ClapTrap *Opponent) {
	switch (PlayerAction()) {
		case HEAL:
			bot->beRepaired((std::rand() % 10) + (std::rand() % 10) + (std::rand() % 10));
			break;
		case GUARD:
			bot->guardGate();
			break;
		case FORFEIT:
			bot->setHitPoints(0);
			std::cout << "[ " << std::setw(12) << std::left << *bot << RE << " " << std::setw(3) << std::right << bot->getHitPoints() << "  " << CY << std::setw(3) << std::right << bot->getEnergyPoints() << RC << " ]\t";
			std::cout << RE << "Self-Destruct Engaged!" << RC << std::endl;
			break;
		default:
			bot->setAttackDamage((std::rand() % 15) + 10);
			bot->attack(Opponent->getName());
			break;
	}
}

void	versusBattle( void ) {
	FragTrap	Computer("J0CK");
	ScavTrap	Player(askName());
	bool		EnergyLeft;
	bool		BotDestroyed;
	int			Turn;

	EnergyLeft = Player.getEnergyPoints() or Computer.getEnergyPoints();
	BotDestroyed = !Player.getHitPoints() or !Computer.getHitPoints();
	Turn = (std::rand() % 2);
	while (EnergyLeft and !BotDestroyed) {
		if (Turn == COMPUTER) {
			ComputerTurn(&Computer, &Player);
			Turn = PLAYER;
		}
		else {
			PlayerTurn(&Player, &Computer);
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
			versusBattle();
			break;
		default:
			std::cout << "Leaving the Arena" << std::endl;
			break;
	}
	return 0;
}