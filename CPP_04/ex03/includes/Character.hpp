#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "Unequipped.hpp"


class Character : public ICharacter {
	private:
		std::string			_Name;
		static const int	_InventorySize = 4;
		AMateria*			_Materias[Character::_InventorySize];

	public:
		Character( void );
		Character(std::string const & name);
		Character( Character const & src );
		~Character( void );

		Character	&operator=( Character const & src );

		void						setName( std::string const value );
		virtual std::string const &	getName( void ) const;
		virtual	void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

std::ostream	&operator<<( std::ostream & ostream, Character const & src );


#endif
