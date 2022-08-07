#include "includes/AMateria.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "includes/Character.hpp"
#include "includes/Verbose.hpp"
#include "includes/MateriaSource.hpp"

void	askVerbose( void ) {
	std::string	cmd;
	bool		ask;
	
	ask = true;
	while (ask) {
		std::cout << "Verbose activated ( y / N ) ? ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return;
		if (!cmd.compare("y")) {
			Verbose::On = true;
			ask = false;
		}
		else if (!cmd.compare("N")) {
			Verbose::On = false;
			ask = false;
		}
		else
			std::cout << RE << "Invalid command" << RC << std::endl;
	}
}

int	main ( void ) {
	askVerbose();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	//AMateria* MateriaOne = new Ice();
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	//MateriaOne = new Cure();
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}