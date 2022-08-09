#include "Form.hpp"

Form::Form( std::string const & Name, int Signature, int Execution ) : _name(Name), _gradeSign(Signature), _gradeExec(Execution), _signed(false) {
	Bureaucrat::VerboseMsg("Form Named & Graded Constructor called");
	if (Signature < Form::_gradeMax or Execution < Form::_gradeMax)
		throw Form::GradeTooHighException();
	else if (Signature > Form::_gradeMin or Execution > Form::_gradeMin)
		throw Form::GradeTooLowException();
}

Form::Form( Form const & src ) :  _name(src.getName()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec()), _signed(src.getSigned())  {
	Bureaucrat::VerboseMsg("Form Copy Constructor called");
	if (this->_gradeSign < Form::_gradeMax or this->_gradeExec < Form::_gradeMax)
		throw Form::GradeTooHighException();
	else if (this->_gradeSign > Form::_gradeMin or this->_gradeExec > Form::_gradeMin)
		throw Form::GradeTooLowException();
}

Form::~Form( void ) {
	Bureaucrat::VerboseMsg("Form Destructor called");
}

Form	&Form::operator=( Form const & src ) {
	Bureaucrat::VerboseMsg("Form Assignation Operator called\nNeither Name nor Grades can be changed.");
	this->_signed = src.getSigned();
	return (*this);
}

std::string	Form::getName( void ) const {
	return (this->_name);
}

void	Form::setSigned( bool const value ) {
	this->_signed = value;
}

bool	Form::getSigned( void ) const {
	return (this->_signed);
}

int	Form::getGradeSign( void ) const {
	return (this->_gradeSign);
}

int	Form::getGradeExec( void ) const {
	return (this->_gradeExec);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form Exception: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form Exception: Grade too Low";
}

const char* Form::NotaValidFormException::what() const throw()
{
	return "Form Exception: Not a Valid Form";
}

void	Form::beSigned( Bureaucrat *signatory) {
	if (signatory) {
		if (signatory->getGrade() <= this->_gradeSign)
			this->_signed = true;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	else
		throw Bureaucrat::NotaValidBureaucratException();
}

std::ostream	&operator<<( std::ostream & ostream, Form const & src ) {
	try {
		ostream << src.getName() << " form [G-S-" << src.getGradeSign() << "] [G-E-" << src.getGradeExec() << "]";
	}
	catch (std::exception const &e) {
		ostream << "\r               \r";
	}
	return (ostream);
}