#include "includes/Unequipped.hpp"

int			Unequipped::Total = 0;
Unequipped	*Unequipped::First = NULL;
Unequipped	*Unequipped::Last = NULL;

Unequipped::Unequipped( void ) {
	if (!Unequipped::First) {
		Unequipped::First = this;
		Unequipped::Last = this;
		this->Prev = NULL;
		this->Next = NULL;
	}
	else {
		this->Prev = Unequipped::Last;
		Unequipped::Last->Next = this;
		this->Next = NULL;
		Unequipped::Last = this;
	}
	Unequipped::Total++;
}

Unequipped::Unequipped( AMateria *materia ) : Materia(materia) {
	Unequipped			*tmp = Unequipped::First;

	this->Prev = NULL;
	this->Next = NULL;
	while (tmp and tmp->Materia != materia) 
		tmp = tmp->Next;
	if (!tmp) {
		if (!Unequipped::First) {
			Unequipped::First = this;
			Unequipped::Last = this;
		}
		else {
			this->Prev = Unequipped::Last;
			Unequipped::Last->Next = this;
			Unequipped::Last = this;
		}
		Unequipped::Total++;
	}
	else 
		delete this;
}

Unequipped::Unequipped( Unequipped const & src ) {
	if (!Unequipped::First) {
		Unequipped::First = this;
		Unequipped::Last = this;
		this->Prev = NULL;
		this->Next = NULL;
	}
	else {
		this->Prev = Unequipped::Last;
		Unequipped::Last->Next = this;
		this->Next = NULL;
		Unequipped::Last = this;
	}
	this->Materia = src.Materia;
	Unequipped::Total++;
}

Unequipped::~Unequipped( void ) {
	Verbose::msg("Unequipped Destructor Called");
	if (this == Unequipped::First or this->Prev) {
		if (this != Unequipped::First and this != Unequipped::Last) {
			this->Prev->Next = this->Next;
			this->Next->Prev = this->Prev;
		}
		if (this == Unequipped::First) {
			if (this->Next)
				this->Next->Prev = NULL;
			Unequipped::First = this->Next;
		}
		if (this == Unequipped::Last) {
			if (this->Prev)
				this->Prev->Next = NULL;
			Unequipped::Last = this->Prev;
		}
		Unequipped::Total--;
	}
}

Unequipped	&Unequipped::operator=( Unequipped const & src ) {
	this->Materia = src.Materia;
	return (*this);
}

void	Unequipped::clearList( void ) {
	Unequipped		*tmp = Unequipped::First;
	Unequipped		*next;

	while (tmp) {
		next = tmp->Next;
		delete tmp->Materia;
		delete tmp;
		tmp = next;
	}
}