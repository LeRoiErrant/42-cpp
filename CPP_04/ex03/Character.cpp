#include "includes/Character.hpp"

Character::Character( void ) : _Name("Unamed Character") {
	Verbose::msg("Character Base Constructor Called");
	for (int i = 0; i < Character::_InventorySize; i++) {
		this->_Materias[i] = NULL;
	}
}

Character::Character( std::string const & name ) : _Name(name) {
	Verbose::msg("Character Named Constructor Called");
	for (int i = 0; i < Character::_InventorySize; i++) {
		this->_Materias[i] = NULL;
	}
}

Character::Character( Character const & src ) {
	Verbose::msg("Character Copy Constructor Called");
	for (int i = 0; i < Character::_InventorySize; i++) {
		if (src._Materias[i])
			this->_Materias[i] = src._Materias[i]->clone();
		else
			this->_Materias[i] = NULL;
	}
}

Character::~Character( void ) {
	Verbose::msg("Character Destructor Called");
	for (int i = 0; i < Character::_InventorySize; i++) {
		if (this->_Materias[i]) {
			delete this->_Materias[i];
		}
	}
	Unequipped::clearList();
}

Character	&Character::operator=( Character const & src ) {
	this->_Name = src.getName();
	for (int i = 0; i < Character::_InventorySize; i++) {
		if (this->_Materias[i])
			delete this->_Materias[i];
	}
	for (int i = 0; i < Character::_InventorySize; i++) {
		if (src._Materias[i])
			this->_Materias[i] = src._Materias[i]->clone();
		else
			this->_Materias[i] = NULL;
	}
	return (*this);
}

void	Character::setName( std::string const value ) {
	this->_Name = value;
}

std::string const &	Character::getName( void ) const {
	return (this->_Name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < Character::_InventorySize; i++) {
		if (!this->_Materias[i]) {
			this->_Materias[i] = m->clone();
			delete m;
			return;
		}
	}
}

void	Character::unequip(int idx) {
	std::stringstream	ss;
	if (this->_Materias[idx]) {
		new Unequipped(this->_Materias[idx]);
		this->_Materias[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 and idx < 4 and this->_Materias[idx])
		this->_Materias[idx]->use(target);
}

std::ostream	&operator<<( std::ostream & ostream, Character const & src ) {
	ostream << src.getName();
	return (ostream);
}