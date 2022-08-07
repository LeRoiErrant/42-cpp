#include "Animal.hpp"

Animal::Animal( void ) : _type("Daemon") {
	std::cout << "Animal Base Constructor called" << std::endl;
}

Animal::Animal( Animal const & src ) {
	std::cout << "Animal Copy Constructor called" << std::endl;
	this->_type = src.gettype();
}

Animal::~Animal( void ) {
	std::cout << this->_type << " Animal Destructor called" << std::endl;
	this->_type.clear();
}

Animal	&Animal::operator=( Animal const & src ) {
	this->_type = src.gettype();
	return (*this);
}

void	Animal::settype( std::string const value ) {
	this->_type = value;
}

std::string	Animal::gettype( void ) const {
	return (this->_type);
}
