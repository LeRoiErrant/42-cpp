#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define ITAL "\033[3m"
# define BOLD "\033[1m"
# define RC "\033[0m"

class Animal {
	private:

	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( Animal const & src );
		virtual ~Animal( void );

		Animal	&operator=( Animal const & src );

		void			settype( std::string const value );
		std::string		gettype( void ) const;

		virtual void	makeSound(void) const = 0;
};

#endif
