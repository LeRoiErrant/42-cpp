#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		static const int	_Memory = 4;
		AMateria*			_Materias[MateriaSource::_Memory];
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const & src );
		virtual ~MateriaSource( void );

		MateriaSource	&operator=( MateriaSource const & src );

		virtual void		learnMateria(AMateria* materia);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
