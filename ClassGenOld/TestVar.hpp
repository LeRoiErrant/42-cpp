#ifndef TESTVAR_HPP
# define TESTVAR_HPP

# include <iostream>

class TestVar {
	private:
		char*	_Test;
		std::string	_Essai;

	public:
		TestVar( void );
		TestVar( TestVar const & src );
		~TestVar( void );

		TestVar	&operator=( TestVar const & src );

		void		setTest( char* const value );
		char*	getTest( void ) const;
		void		setEssai( std::string const value );
		std::string	getEssai( void ) const;

};

#endif
