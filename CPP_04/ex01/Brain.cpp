#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain Base Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i].clear();
}

Brain::Brain( Brain const & src ) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdea(i);
}

Brain::~Brain( void ) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i].clear();
}

Brain	&Brain::operator=( Brain const & src ) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdea(i);
	return (*this);
}

void	Brain::setIdea( unsigned int i, std::string const value ) {
	if (i < 100)
		this->_ideas[i] = value;
}

std::string	Brain::getIdea( unsigned int i ) const {
	if (i < 100)
		return (this->_ideas[i]);
	return (std::string());
}

