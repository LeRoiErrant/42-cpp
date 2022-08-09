#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form{
	private:
		std::string const	_target;

		ShrubberyCreationForm( void );
	public:
		ShrubberyCreationForm( std::string const & target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm	&operator=( ShrubberyCreationForm const & src );

		std::string const	getTarget( void ) const;

		virtual void		execute( Bureaucrat const * executor ) const;
};

#endif
