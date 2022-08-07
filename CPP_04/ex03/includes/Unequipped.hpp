#ifndef UNEQUIPPED_HPP
# define UNEQUIPPED_HPP

# include "AMateria.hpp"

class Unequipped {
	private:

	public:
		Unequipped( void );
		Unequipped( Unequipped const & src );
		Unequipped	&operator=( Unequipped const & src );
		Unequipped( AMateria *materia);
		~Unequipped( void );

		static	int			Total;
		static Unequipped	*First;
		static Unequipped	*Last;
		Unequipped			*Prev;
		AMateria			*Materia;
		Unequipped			*Next;
		static void			clearList(void);
};

#endif
