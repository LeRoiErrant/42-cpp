#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat Base Constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal(src) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << this->_type << " WrongCat Destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=( WrongCat const & src ) {
	this->_type = src.gettype();
	return (*this);
}

void	WrongCat::makeSound( void ) const {
	std::cout << ITAL << "Woem" << RC << std::endl;
}