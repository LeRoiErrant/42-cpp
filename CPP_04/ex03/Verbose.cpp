#include "includes/Verbose.hpp"

bool	Verbose::On = true;

Verbose::Verbose( void ) {
}

Verbose::Verbose( Verbose const & src ) {
	*this = src;
}

Verbose::~Verbose( void ) {
}

Verbose	&Verbose::operator=( Verbose const & src ) {
	(void) src;
	return (*this);
}

void	Verbose::msg(std::string const & msg) {
	if (Verbose::On)
		std::cout << msg << std::endl;
}

