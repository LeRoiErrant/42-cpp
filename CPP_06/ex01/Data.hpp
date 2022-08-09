#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	private:

	public:
		Data( void );
		Data( Data const & src );
		~Data( void );

		Data	&operator=( Data const & src );

		std::string	test;


};

#endif
