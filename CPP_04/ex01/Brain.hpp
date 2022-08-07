#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain( void );
		Brain( Brain const & src );
		~Brain( void );

		Brain	&operator=( Brain const & src );

		void		setIdea( unsigned int i, std::string const value );
		std::string	getIdea( unsigned int i ) const;

};

#endif
