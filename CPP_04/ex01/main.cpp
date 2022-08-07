#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main( void ) {
	Cat*	Gilgamesh = new Cat();
	Dog*	Kodac = new Dog();
	
	Gilgamesh->setIdea(0, "I want food");
	Kodac->setIdea(0, "Balle");
	std::cout << "Gilgamesh think: " << Gilgamesh->getIdea(0) << std::endl;
	std::cout << "Kodac think: " << Kodac->getIdea(0) << std::endl;	
	Cat*	LucyPurr = new Cat(*Gilgamesh);
	Dog*	AnotherDog = new Dog(*Kodac);
	std::cout << "LucyPurr think: " << LucyPurr->getIdea(0) << std::endl;
	std::cout << "AnotherDog think: " << AnotherDog->getIdea(0) << std::endl;	
	LucyPurr->setIdea(0, "I want to play");
	AnotherDog->setIdea(1, "FOOD");
	std::cout << "Kodac think: " << Kodac->getIdea(1) << std::endl;	
	std::cout << "AnotherDog think: " << AnotherDog->getIdea(1) << std::endl;	
	std::cout << "LucyPurr think: " << LucyPurr->getIdea(0) << std::endl;
	std::cout << "Gilgamesh think: " << Gilgamesh->getIdea(0) << std::endl;
	Gilgamesh->setIdea(0, "I love to eat");
	std::cout << "LucyPurr think: " << LucyPurr->getIdea(0) << std::endl;
	std::cout << "Gilgamesh think: " << Gilgamesh->getIdea(0) << std::endl;

	delete Gilgamesh;
	delete LucyPurr;
	delete Kodac;
	delete AnotherDog;
	return (0);
}