#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("Nomead") {
		std::cout << "WrongAnimal Base Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) : _type(src.gettype()) {
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << this->_type << " WrongAnimal Destructor called" << std::endl;
	this->_type.clear();
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const & src ) {
	this->_type = src.gettype();
	return (*this);
}

void	WrongAnimal::settype( std::string const value ) {
	this->_type = value;
}

std::string	WrongAnimal::gettype( void ) const {
	return (this->_type);
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << BOLD << ITAL << "Haay" << RC << std::endl;
}