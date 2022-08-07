#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <sstream>
# include "Verbose.hpp"
# include "ICharacter.hpp"


class AMateria {
	private:
		AMateria( void );

	protected:
		std::string	_Type;
		
	public:
		AMateria(std::string const & type);
		AMateria( AMateria const & src );
		virtual ~AMateria( void );

		AMateria	&operator=( AMateria const & src );

		void				setType( std::string const & value );
		std::string const &	getType( void ) const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target) = 0;
};

#endif
