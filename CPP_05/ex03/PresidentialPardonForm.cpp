#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : Form("presidential pardon", 25, 5), _target(target) {
	Bureaucrat::VerboseMsg("PresidentialPardonForm Targeted Constructor called");
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form(src), _target(src.getTarget()) {
	Bureaucrat::VerboseMsg("PresidentialPardonForm Copy Constructor called");
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	Bureaucrat::VerboseMsg("PresidentialPardonForm Destructor called");
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const & src ) {
	Bureaucrat::VerboseMsg("PresidentialPardonForm Assignation Operator called\nNeither Name nor Grades can be changed.");
	this->setSigned(src.getSigned());
	return (*this);
}

std::string const	PresidentialPardonForm::getTarget( void ) const {
	return (this->_target);
}

void	PresidentialPardonForm::execute( Bureaucrat const * executor ) const {
	if ( executor ) {
		this->isSignedAndExecutable(*executor);
		std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw Bureaucrat::NotaValidBureaucratException();
}

Form	*PresidentialPardonForm::writeForm( std::string const & target) {
	return (new PresidentialPardonForm(target));
}