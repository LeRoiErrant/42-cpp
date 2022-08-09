#include "Test.hpp"

Test::Test( void ) {
}

Test::Test( Test const & src ) {
	*this = src;
}

Test::~Test( void ) {
}

Test	&Test::operator=( Test const & src ) {
	return (*this);
}
