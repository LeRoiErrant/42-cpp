#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		std::string const	_target;

		PresidentialPardonForm( void );
	public:
		PresidentialPardonForm( std::string const & target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm( void );

		PresidentialPardonForm	&operator=( PresidentialPardonForm const & src );

		std::string const	getTarget( void ) const;

		virtual void		execute( Bureaucrat const * executor ) const;
		static Form			*writeForm( std::string const & target);
};

#endif
