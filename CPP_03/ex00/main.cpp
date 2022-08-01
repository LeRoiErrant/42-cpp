#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

enum bot {
	HEAVY,
	QUICK
};

enum action {
	HEAL,
	ATTACK
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

void	Battle(ClapTrap *Quick, ClapTrap *Heavy) {
	bool 	EnergyLeft;
	bool	BotDestroyed;

	Quick->setAttackDamage(2);
	Heavy->setAttackDamage(6);
	EnergyLeft = Quick->getEnergyPoints() and Heavy->getEnergyPoints();
	BotDestroyed = !Quick->getHitPoints() or !Heavy->getHitPoints();
	while (EnergyLeft and !BotDestroyed) {
		if (std::rand() % 3 == HEAVY)
			take_turn(Heavy, Quick);
		else
			take_turn(Quick, Heavy);
		EnergyLeft = Quick->getEnergyPoints() and Heavy->getEnergyPoints();
		BotDestroyed = !Quick->getHitPoints() or !Heavy->getHitPoints();
	usleep(500000);
	}
	if (BotDestroyed) {
		if (!Quick->getHitPoints())
			std::cout << MA << "WE HAVE A WINNER! " << Heavy->getName() << " destroyed " << Quick->getName() << "!" << RC << std::endl; 
		else
			std::cout << MA << "WE HAVE A WINNER! " << Quick->getName() << " destroyed " << Heavy->getName() << "!" << RC << std::endl;
	}
	else
		std::cout << MA << "IT'S A DRAW! Both Bots have no Energy left!" << RC <<std::endl;
}

int	main( void ) {
	ClapTrap	Bobby("Bobby");
	ClapTrap	John("John");

	std::srand(time(NULL));
	Battle(&Bobby, &John);
	return 0;
}