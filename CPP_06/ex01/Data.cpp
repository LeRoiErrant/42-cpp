#include "Data.hpp"

Data::Data( void ) : test(std::string()) {
}

Data::Data( Data const & src ) : test(src.test) {
}

Data::~Data( void ) {
}

Data	&Data::operator=( Data const & src ) {
	this->test = src.test;
	return (*this);
}

