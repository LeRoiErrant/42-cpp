#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>

class Template {
	private:

	public:
		Template( void );
		Template( Template const & src );
		~Template( void );

		Template	&operator=( Template const & src );
};

#endif
