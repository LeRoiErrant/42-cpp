#include "includes/AMateria.hpp"

AMateria::AMateria( void ) : _Type(std::string()) {
	Verbose::msg("AMateria Base Constructor called");
}

AMateria::AMateria(std::string const & type) : _Type(type) {
	Verbose::msg("AMateria Type Constructor called");
}

AMateria::AMateria( AMateria const & src ) {
	Verbose::msg("AMateria Copy Constructor called");
	this->_Type = src.getType();
}

AMateria::~AMateria( void ) {
	Verbose::msg("AMateria Destructor called");
	this->_Type.clear();
}

AMateria	&AMateria::operator=( AMateria const & src ) {
	Verbose::msg("AMateria Assignation Operator called");
	this->_Type = src.getType();
	return (*this);
}

void	AMateria::setType( std::string const & value ) {
	this->_Type = value;
}

std::string const &	AMateria::getType( void ) const {
	return (this->_Type);
}
