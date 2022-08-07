#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
	this->_type = "Dog";
	std::cout << "Dog Base Constructor called" << std::endl;
}

Dog::Dog( Dog const & src ) : Animal(src) {
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog( void ) {
	std::cout << this->_type << " Dog Destructor called" << std::endl;
}

Dog	&Dog::operator=( Dog const & src ) {
	this->_type = src.gettype();
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << ITAL << "Woof" << RC << std::endl;
}