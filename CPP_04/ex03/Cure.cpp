#include "includes/Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	Verbose::msg("Cure Base Constructor Called");
}

Cure::Cure( Cure const & src ) : AMateria(src) {
	Verbose::msg("Cure Copy Constructor Called");
}

Cure::~Cure( void ) {
	Verbose::msg("Cure Destructor Called");
}

Cure	&Cure::operator=( Cure const & src ) {
	Verbose::msg("Cure Assignation Operattor Called");
	this->_Type = src.getType();
	return (*this);
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void		Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}