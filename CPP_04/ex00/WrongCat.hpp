#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	private:

	public:
		WrongCat( void );
		WrongCat( WrongCat const & src );
		virtual ~WrongCat( void );

		WrongCat	&operator=( WrongCat const & src );

		virtual void	makeSound(void) const;
};

#endif
