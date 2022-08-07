#include "Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Cat Base Constructor called" << std::endl;
	this->_type = "Cat";
	this->_Brain = new Brain();
}

Cat::Cat( Cat const & src ) : Animal (src) {
		std::cout << "Cat Copy Constructor called" << std::endl;
		this->_Brain = new Brain(*src.getBrain());
}

Cat::~Cat( void ) {
	std::cout << this->_type << " Cat Destructor called" << std::endl;
	delete this->_Brain;
}

Cat	&Cat::operator=( Cat const & src ) {
	this->_type = src.gettype();
	delete this->_Brain;
	this->_Brain = new Brain(*src.getBrain());
	return (*this);
	return (*this);
}

Brain*	Cat::getBrain( void ) const {
	return (this->_Brain);
}

void	Cat::makeSound( void ) const {
	std::cout << ITAL << "Meow" << RC << std::endl;
}

std::string	Cat::getIdea( unsigned int i ) const {
	if (i < 100)
		return (this->_Brain->getIdea(i));
	return (std::string());
}

void	Cat::setIdea( unsigned int i, std::string const idea) {
	if (i < 100)
		this->_Brain->setIdea(i, idea);
}