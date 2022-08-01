#include "TestVar.hpp"

TestVar::TestVar( void ) {
}

TestVar::TestVar( TestVar const & src ) {
	*this = src;
}

TestVar::~TestVar( void ) {
}

TestVar	&TestVar::operator=( TestVar const & src ) {
	return (*this);
}

void	TestVar::setTest( char* const value ) {
	this->_Test = value;
}

char*	TestVar::getTest( void ) const {
	return (this->_Test);
}

void	TestVar::setEssai( std::string const value ) {
	this->_Essai = value;
}

std::string	TestVar::getEssai( void ) const {
	return (this->_Essai);
}

