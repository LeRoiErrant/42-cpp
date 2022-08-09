#include "Bureaucrat.hpp"

int	main( void ) {
	Bureaucrat	*Tom; 
	try {
		Tom = new Bureaucrat("Tom", 1);
	}
	catch(std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << *Tom << std::endl;
	Bureaucrat	*Bobby;
	try {
		Bobby = new Bureaucrat("Bobby", 152);
		std::cout << *Bobby << std::endl;
	}
	catch(std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << *Tom << std::endl;
	std::cout << *Bobby << std::endl;
	Tom->demote();
	std::cout << *Tom << std::endl;
	Tom->promote();
	std::cout << *Tom << std::endl;
	Tom->promote();
	std::cout << *Tom << std::endl;
	Bobby->promote();
	return (0);
}