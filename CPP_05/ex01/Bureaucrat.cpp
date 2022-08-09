#include "Bureaucrat.hpp"

bool	Bureaucrat::Verbose = true;

void	Bureaucrat::VerboseMsg(std::string const & msg) {
	if (Bureaucrat::Verbose)
		std::cout << msg << std::endl;
}

void	Bureaucrat::setVerbose(bool const & value) {
	Bureaucrat::Verbose = value;
}

Bureaucrat::Bureaucrat( std::string const & Name, int Grade ) : _name(Name), _grade(Grade) {
	Bureaucrat::VerboseMsg("Bureaucrat Named & Graded Constructor called");
	if (Grade < Bureaucrat::_gradeMax)
		throw Bureaucrat::GradeTooHighException();
	else if (Grade > Bureaucrat::_gradeMin)
		throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::Bureaucrat( Bureaucrat const & src ): _name(src.getName()), _grade(src.getGrade()) {
	Bureaucrat::VerboseMsg("Bureaucrat Copy Constructor called");
	if (this->_grade < Bureaucrat::_gradeMax)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::_gradeMin)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat( void ) {
	Bureaucrat::VerboseMsg("Bureaucrat Copy Destructor called");
}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const & src ) {
	Bureaucrat::VerboseMsg("Bureaucrat Assignation Operator called. Only the Grade is copied");
	this->_grade = src.getGrade();
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Exception: Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Exception: Grade too Low";
}

const char* Bureaucrat::NotaValidBureaucratException::what() const throw()
{
	return "Bureaucrat Exception: Not a Valid Bureaucrat";
}

std::string const	Bureaucrat::getName( void ) const {
	return (this->_name);
}

void	Bureaucrat::setGrade( int const & value ) {
	this->_grade = value;
}

int	Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

std::ostream	&operator<<( std::ostream & ostream, Bureaucrat const & src ) {
	try {
		ostream << "Bureaucrat " << src.getName() << " [G-" << src.getGrade() << "]";
	}
	catch (std::exception const &e) {
		ostream << "\r               \r";
	}
	return (ostream);
}

void	Bureaucrat::promote( void ) {
	std::stringstream ss;

	try {
		ss <<  *this << " Promotion";
		Bureaucrat::VerboseMsg(ss.str());
		this->_grade--;
		if (this->_grade < Bureaucrat::_gradeMax)
			throw Bureaucrat::GradeTooHighException();
	}
	catch ( std::exception const &e ) {
		std::cerr << e.what() << std::endl;
		this->_grade++;
	}
}

void	Bureaucrat::demote( void ) {
	std::stringstream ss;
	
	try {
		ss <<  *this << " Demotion";
		Bureaucrat::VerboseMsg(ss.str());
		this->_grade++;
		if (this->_grade > Bureaucrat::_gradeMin)
			throw Bureaucrat::GradeTooLowException();
	}
	catch ( std::exception const &e ) {
		std::cerr << e.what() << std::endl;
		this->_grade--;
	}
}

void	Bureaucrat::signForm( Form * toSign) {
	try {
		if (toSign) {
			toSign->beSigned(this);
			std::cout << *this << " signed " << *toSign << std::endl; 
		}
		else
			throw Form::NotaValidFormException();
	}
	catch (std::exception const & e) {
		std::cout << *this << " couldn't sign ";
		if (toSign)
			std::cout << *toSign << " "; 
		std::cout << "because " << e.what() << std::endl;
	}
}