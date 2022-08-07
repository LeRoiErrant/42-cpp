#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
	this->_type = "Dog";
	std::cout << "Dog Base Constructor called" << std::endl;
	this->_Brain = new Brain();
}

Dog::Dog( Dog const & src ) : Animal(src) {
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->_Brain = new Brain(*src.getBrain());
}

Dog::~Dog( void ) {
	std::cout << this->_type << " Dog Destructor called" << std::endl;
	delete this->_Brain;
}

Dog	&Dog::operator=( Dog const & src ) {
	this->_type = src.gettype();
	delete this->_Brain;
	this->_Brain = new Brain(*src.getBrain());
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << ITAL << "Woof" << RC << std::endl;
}

Brain*	Dog::getBrain( void ) const {
	return (this->_Brain);
}

std::string	Dog::getIdea( unsigned int i ) const {
	if (i < 100)
		return (this->_Brain->getIdea(i));
	return (std::string());
}

void	Dog::setIdea( unsigned int i, std::string const idea) {
	if (i < 100)
		this->_Brain->setIdea(i, idea);
}