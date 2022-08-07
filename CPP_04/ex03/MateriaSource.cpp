#include "includes/MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	Verbose::msg("MateriaSource Base Constructor Called");
	for (int i = 0; i < MateriaSource::_Memory; i++) {
		this->_Materias[i] = NULL;
	}
}

MateriaSource::MateriaSource( MateriaSource const & src ) {
	Verbose::msg("Materia Source Copy Constructor Called");
	for (int i = 0; i < MateriaSource::_Memory; i++) {
		if (src._Materias[i])
			this->_Materias[i] = src._Materias[i]->clone();
		else
			this->_Materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource( void ) {
	Verbose::msg("MateriaSource Destructor Called");
	for (int i = 0; i < MateriaSource::_Memory; i++) {
		if (this->_Materias[i]) {
			delete this->_Materias[i];
		}
	}
}

MateriaSource	&MateriaSource::operator=( MateriaSource const & src ) {
	for (int i = 0; i < MateriaSource::_Memory; i++) {
		if (this->_Materias[i])
			delete this->_Materias[i];
	}
	for (int i = 0; i < MateriaSource::_Memory; i++) {
		if (src._Materias[i])
			this->_Materias[i] = src._Materias[i]->clone();
		else
			this->_Materias[i] = NULL;
	}
	return (*this);
}


void		MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < MateriaSource::_Memory; i++) {
		if (!this->_Materias[i]) {
			this->_Materias[i] = materia;
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MateriaSource::_Memory; i++) {
		if (!type.compare(this->_Materias[i]->getType()))
			return (this->_Materias[i]->clone());
	}
	return (0);
}