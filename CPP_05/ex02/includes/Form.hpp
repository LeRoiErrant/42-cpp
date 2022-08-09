#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		int const			_gradeSign;
		int const			_gradeExec;
		bool				_signed;

		static int const	_gradeMax = 1;
		static int const	_gradeMin = 150;

		Form( void );

	public:
		Form( std::string const & Name, int Signature, int Execution );
		Form( Form const & src );
		~Form( void );

		Form	&operator=( Form const & src );

		void		setSigned( bool const value );

		std::string	getName( void ) const;
		bool		getSigned( void ) const;
		int			getGradeSign( void ) const;
		int			getGradeExec( void ) const;

		void				beSigned( Bureaucrat * signatory );
		void				isSignedAndExecutable( Bureaucrat const & exectutor ) const;
		virtual void		execute( Bureaucrat const * executor ) const = 0;

		class GradeTooHighException: public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			virtual const char* what() const throw();
		};
		class NotSignedException: public std::exception {
			virtual const char* what() const throw();
		};
		class NotaValidFormException: public std::exception {
			virtual const char* what() const throw();
		};

};

std::ostream	&operator<<( std::ostream & ostream, Form const & src );

#endif
