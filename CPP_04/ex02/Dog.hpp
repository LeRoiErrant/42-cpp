#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain*	_Brain;
	public:
		Dog( void );
		Dog( Dog const & src );
		virtual ~Dog( void );

		Dog	&operator=( Dog const & src );

		Brain*		getBrain( void ) const;
		std::string	getIdea( unsigned int i ) const;
		void		setIdea( unsigned int i, std::string const idea );

		virtual void	makeSound(void) const;
};

#endif
