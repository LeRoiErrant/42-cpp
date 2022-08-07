#include "includes/Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
	Verbose::msg("Ice Base Constructor called");
}

Ice::Ice( Ice const & src ) : AMateria(src) {
	Verbose::msg("Ice Copy Constructor called");
}

Ice::~Ice( void ) {
	Verbose::msg("Ice Destructor called");
}

Ice	&Ice::operator=( Ice const & src ) {
	Verbose::msg("Ice Assignation Operator called");
	this->_Type = src.getType();
	return (*this);
}

AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

void		Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}