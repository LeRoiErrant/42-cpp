#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat Base Constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat( Cat const & src ) : Animal (src) {
		std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat( void ) {
	std::cout << this->_type << " Cat Destructor called" << std::endl;
}

Cat	&Cat::operator=( Cat const & src ) {
	this->_type = src.gettype();
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << ITAL << "Meow" << RC << std::endl;
}