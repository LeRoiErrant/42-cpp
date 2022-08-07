#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define ITAL "\033[3m"
# define BOLD "\033[1m"
# define RC "\033[0m"

class WrongAnimal {
	private:
	
	protected:
		std::string	_type;

	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal( void );

		WrongAnimal	&operator=( WrongAnimal const & src );

		void		settype( std::string const value );
		std::string	gettype( void ) const;

		virtual void	makeSound(void) const;
};

#endif
