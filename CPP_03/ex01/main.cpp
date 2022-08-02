#include "ScavTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sstream>
#define N_CLAP 21

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
	GUARD,
	ATTACK
};

bool	cerberror(std::string msg, char *arg, bool result)
{
	if (!msg.empty())
		std::cerr << msg;
	if (arg)
		std::cerr << arg;
	std::cerr << std::endl;
	return (result);
}

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

void	take_turn(ClapTrap *bot, ScavTrap *Opponent) {
	switch (std::rand() % 4) {
		case HEAL:
			bot[std::rand() % N_CLAP].beRepaired((std::rand() % 4) + 1);
			break;
		default:
			bot[std::rand() % N_CLAP].attack(Opponent->getName());
			break;
	}
}

void	take_turn(ScavTrap *bot, ClapTrap *Opponent) {
	switch (std::rand() % 4) {
		case HEAL:
			bot->beRepaired((std::rand() % 4) + 1);
			break;
		case GUARD:
			bot->guardGate();
			break;
		default:
			bot->attack(Opponent[std::rand() % N_CLAP].getName());
			break;
	}
}

ClapTrap	*assembleClapTrapArmy( unsigned int N, std::string name) {
	ClapTrap			*Army = new ClapTrap[N];
	std::stringstream	ssname;
	
	for (unsigned int i = 0; i < N; i++) {
		ssname << name << "-" << i;
		Army[i].setName(ssname.str());
		ssname.str(std::string());
		Army[i].setAttackDamage((std::rand() % 5) + 1);
	}
	return (Army);
}

bool	checkQuickEnergy( ClapTrap *Quick ) {
	unsigned int check = 0;

	for (int i = 0; i < N_CLAP; i++) {
		if (Quick[i].getEnergyPoints() > 0)
			check++;
	}
	if (check > 0)
		return (true);
	else
		return (false);
}

bool	checkQuickHealth( ClapTrap *Quick ) {
	unsigned int check = 0;

	for (int i = 0; i < N_CLAP; i++) {
		if (Quick[i].getHitPoints() > 0)
			check++;
	}
	if (check > 0)
		return (true);
	else
		return (false);
}

bool	Battle( void ) {
	bool 		EnergyLeft;
	bool		BotDestroyed;
	ClapTrap	*Quick;
	ScavTrap	Heavy("Cerberus");

	Quick = assembleClapTrapArmy(N_CLAP, "Bobby");
	if (!Quick)
		return (cerberror("Battlebots: error: Failed to create Clap Army", 0, false));
	EnergyLeft = checkQuickEnergy(Quick) and Heavy.getEnergyPoints();
	BotDestroyed = !checkQuickHealth(Quick) or !Heavy.getHitPoints();
	while (EnergyLeft and !BotDestroyed) {
		if (std::rand() % 4 == HEAVY)
			take_turn(&Heavy, Quick);
		else
			take_turn(Quick, &Heavy);
		EnergyLeft = checkQuickEnergy(Quick) and Heavy.getEnergyPoints();
		BotDestroyed = !checkQuickHealth(Quick) or !Heavy.getHitPoints();
	usleep(500000);
	}
	if (BotDestroyed) {
		if (!checkQuickHealth(Quick))
			std::cout << MA << "WE HAVE A WINNER! " << Heavy.getName() << " destroyed the ClapTrap Army!" << RC << std::endl; 
		else
			std::cout << MA << "WE HAVE A WINNER! " << "The ClapTrap Army destroyed " << Heavy.getName() << "!" << RC << std::endl;
	}
	else
		std::cout << MA << "IT'S A DRAW! All Bots have no Energy left!" << RC <<std::endl;
	delete [] Quick;
	return (true);
}

void	assembly_line( void ) {
	ClapTrap	Bot1("Bot1");
	ScavTrap	Bot2("Bot2");
	ClapTrap	Bot3("Bot3");
	ClapTrap	Clone1(Bot1);
	ScavTrap	Clone2(Bot2);
	ClapTrap	Unamed;
	ClapTrap	*test;

	Unamed = Bot2;
	test = ClapTrap::FirstBot;
	while (test) {
		std::cout << *test << " is next on assembly line" << std::endl;
		test = test->Next;
	}

}

int	ask_mode( void ) {
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
	bool		ask;
	
	ask = true;
	while (ask) {
		std::cout << "Please enter your Bot's Name: ";
		std::getline(std::cin, cmd);
		if (!cmd.length()) {
			std::cout << RE << "Empty name not allowed" << RC << std::endl;
		}
		else
			return (cmd);
	}
	return ("Unamed bot");
}

void	ComputerTurn(ScavTrap *bot, ScavTrap *Opponent) {
	switch (std::rand() % 4) {
		case HEAL:
			bot->beRepaired((std::rand() % 10) + (std::rand() % 10) + (std::rand() % 10));
			break;
		case GUARD:
			bot->guardGate();
			break;
		default:
			bot->setAttackDamage((std::rand() % 15) + 10);
			bot->attack(Opponent->getName());
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
		else if (!cmd.compare("GUARD"))
			return (GUARD);
		else if (!cmd.compare("REPAIR"))
			return (HEAL);
		else
			std::cout << RE << "Invalid command" << RC << std::endl;
	}
	return (ATTACK);
}

void	PlayerTurn(ScavTrap *bot, ScavTrap *Opponent) {
	switch (PlayerAction()) {
		case HEAL:
			bot->beRepaired((std::rand() % 10) + (std::rand() % 10) + (std::rand() % 10));
			break;
		case GUARD:
			bot->guardGate();
			break;
		default:
			bot->setAttackDamage((std::rand() % 15) + 10);
			bot->attack(Opponent->getName());
			break;
	}
}

void	versusBattle( void ) {
	ScavTrap	Computer("Cerberus");
	ScavTrap	Player(askName());
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
		assembly_line();
	std::srand(time(NULL));
	switch (ask_mode()) {
		case SIM:
			if (!Battle())
				return 1;
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