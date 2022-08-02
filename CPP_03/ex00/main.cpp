#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

enum mode {
	QUIT,
	SIM,
	VERSUS
};

enum bot {
	HEAVY,
	QUICK,
	COMPUTER,
	PLAYER
};

enum action {
	HEAL,
	ATTACK,
	FORFEIT
};

void	take_turn(ClapTrap *bot, ClapTrap *Opponent) {
	switch (std::rand() % 4) {
		case HEAL:
			bot->beRepaired((std::rand() % 4) + 1);
			break;
		default:
			bot->attack(Opponent->getName());
			break;
	}
}

void	Battle() {
	ClapTrap	Quick("Bobby");
	ClapTrap	Heavy("John");
	bool 	EnergyLeft;
	bool	BotDestroyed;

	Quick.setAttackDamage(2);
	Heavy.setAttackDamage(6);
	EnergyLeft = Quick.getEnergyPoints() or Heavy.getEnergyPoints();
	BotDestroyed = !Quick.getHitPoints() or !Heavy.getHitPoints();
	while (EnergyLeft and !BotDestroyed) {
		if (std::rand() % 3 == HEAVY)
			take_turn(&Heavy, &Quick);
		else
			take_turn(&Quick, &Heavy);
		EnergyLeft = Quick.getEnergyPoints() or Heavy.getEnergyPoints();
		BotDestroyed = !Quick.getHitPoints() or !Heavy.getHitPoints();
	usleep(500000);
	}
	if (BotDestroyed) {
		if (!Quick.getHitPoints())
			std::cout << MA << "WE HAVE A WINNER! " << Heavy.getName() << " destroyed " << Quick.getName() << "!" << RC << std::endl; 
		else
			std::cout << MA << "WE HAVE A WINNER! " << Quick.getName() << " destroyed " << Heavy.getName() << "!" << RC << std::endl;
	}
	else
		std::cout << MA << "IT'S A DRAW! Both Bots have no Energy left!" << RC <<std::endl;
}

void	assemblyLine( void ) {
	ClapTrap	Bot1("Bot1");
	ClapTrap	Bot2("Bot2");
	ClapTrap	Clone1(Bot1);
	ClapTrap	Unamed;
	ClapTrap	*test;

	Unamed = Bot2;
	test = ClapTrap::FirstBot;
	while (test) {
		std::cout << *test << " is next on assembly line" << std::endl;
		test = test->Next;
	}
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

void	ComputerTurn(ClapTrap *bot, ClapTrap *Opponent) {
	switch (std::rand() % 4) {
		case HEAL:
			bot->beRepaired((std::rand() % 6) + 1);
			break;
		default:
			if ( bot->getHitPoints() < (bot->getInitialHP() / 2)) {
				if (std::rand() % 100 < 50)
					bot->beRepaired((std::rand() % 6) + 1);
				else {
					bot->setAttackDamage((std::rand() % 6) + 1);
					bot->attack(Opponent->getName());
				}
			}
			else {
				bot->setAttackDamage((std::rand() % 6) + 1);
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
		std::cout << MA << "Please select action ( ATTACK / GUARD / REPAIR ): " << RC;
		std::getline(std::cin, cmd);
		if (!cmd.compare("ATTACK"))
			return (ATTACK);
		else if (!cmd.compare("REPAIR"))
			return (HEAL);
		else if (!cmd.compare("FORFEIT"))
			return (FORFEIT);
		else
			std::cout << RE << "Invalid command" << RC << std::endl;
	}
	return (ATTACK);
}

void	PlayerTurn(ClapTrap *bot, ClapTrap *Opponent) {
	switch (PlayerAction()) {
		case HEAL:
			bot->beRepaired((std::rand() % 6) + 1);
			break;
		case FORFEIT:
			bot->setHitPoints(0);
			std::cout << "[ " << std::setw(12) << std::left << *bot << RE << " " << std::setw(3) << std::right << bot->getHitPoints() << "  " << CY << std::setw(3) << std::right << bot->getEnergyPoints() << RC << " ]\t";
			std::cout << RE << "Self-Destruct Engaged!" << RC << std::endl;
			break;
		default:
			bot->setAttackDamage((std::rand() % 6) + 1);
			bot->attack(Opponent->getName());
			break;
	}
}

void	versusBattle( void ) {
	ClapTrap	Computer("Cerberus");
	ClapTrap	Player(askName());
	bool		EnergyLeft;
	bool		BotDestroyed;
	int			Turn;

	EnergyLeft = Player.getEnergyPoints() and Computer.getEnergyPoints();
	BotDestroyed = !Player.getHitPoints() or !Computer.getHitPoints();
	Turn = (std::rand() % 2) + 2;
	while (EnergyLeft and !BotDestroyed) {
		if (Turn == COMPUTER) {
			ComputerTurn(&Computer, &Player);
			Turn = PLAYER;
		}
		else {
			PlayerTurn(&Player, &Computer);
			Turn = COMPUTER;
		}
		EnergyLeft = Player.getEnergyPoints() and Computer.getEnergyPoints();
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