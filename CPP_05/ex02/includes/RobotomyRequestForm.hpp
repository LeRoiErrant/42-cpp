#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public Form {
	private:
		std::string const	_target;

		RobotomyRequestForm( void );
	public:
		RobotomyRequestForm( std::string const & target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm( void );

		RobotomyRequestForm	&operator=( RobotomyRequestForm const & src );
	
		std::string const	getTarget( void ) const;

		virtual void		execute( Bureaucrat const * executor ) const;
};

#endif
