#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum {
	PRESIDENTIAL,
	ROBOTOMY,
	SHRUBBERY,
	UNKNOWN
};

typedef struct s_Forms {
			std::string	Name;
			Form	*(*writeForm)( std::string const &);
} t_Forms;

class Intern {
	private:
		Form	*(*test)( std::string const & );
		static t_Forms	forms[];
		
	public:
		Intern( void );
		Intern( Intern const & src );
		~Intern( void );

		Intern	&operator=( Intern const & src );

		Form	*makeForm( std::string const & FormName, std::string const &Target);
};

std::ostream	&operator<<( std::ostream & ostream, Intern const & src );

#endif
