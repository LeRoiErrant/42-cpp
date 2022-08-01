#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>

class Test {
	private:

	public:
		Test( void );
		Test( Test const & src );
		~Test( void );

		Test	&operator=( Test const & src );
};

#endif
