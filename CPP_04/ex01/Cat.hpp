#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	private:
		Brain*	_Brain;
	public:
		Cat( void );
		Cat( Cat const & src );
		virtual ~Cat( void );

		Cat	&operator=( Cat const & src );

		Brain*	getBrain( void ) const;
		std::string	getIdea( unsigned int i ) const;
		void		setIdea( unsigned int i, std::string const idea );

		virtual void	makeSound(void) const;
};

#endif
