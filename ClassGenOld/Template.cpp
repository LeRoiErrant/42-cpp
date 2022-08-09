#include "Template.hpp"

Template::Template( void ) {	
}

Template::Template( Template const & src ) {
	*this = src;
}


Template::~Template( void ) {
}

Template	&Template::operator=( Template const & src ) {
	return (*this);
}