#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( void ) {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->gettype() << " " << std::endl;
	std::cout << i->gettype() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	delete j;
	delete i;
	return (0);
}