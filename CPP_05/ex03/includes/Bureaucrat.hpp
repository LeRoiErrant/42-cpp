#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <sstream>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;

		static int const	_gradeMax = 1;
		static int const	_gradeMin = 150;
		
		Bureaucrat( void );

	public:
		Bureaucrat( std::string const & Name, int Grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat( void );

		Bureaucrat	&operator=( Bureaucrat const & src );

		void		setGrade( int const & value );

		std::string const	getName( void ) const;
		int					getGrade( void ) const;

		void				promote( void );
		void				demote( void );
		void				signForm( Form * toSign);
		void				executeForm( Form const * form );

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};
		class NotaValidBureaucratException: public std::exception {
			virtual const char* what() const throw();
		};
		static bool			Verbose;
		static void			VerboseMsg(std::string const & msg);
		static void			setVerbose(bool const & value);
};

std::ostream	&operator<<( std::ostream & ostream, Bureaucrat const & src );

# define BLINK "\033[1;5m"
# define BOLD "\033[1m"
# define ITAL "\033[3m"
# define UNDRL "\033[4m"
# define HDDN "\033[8m"
# define GR "\033[32;1m"
# define RE "\033[31;1m"
# define DR "\033[31;1;2m"
# define YE "\033[33;1m"
# define CY "\033[36;1m"
# define LG "\033[37;1;3m"
# define DG "\033[90;1;3m"
# define DGB "\033[90;1m"
# define LB "\033[94;1m"
# define WH "\033[97m"
# define MA "\001\033[1;95m\002"
# define BL "\001\033[1;94m\002"
# define RC "\033[0m"

#endif
