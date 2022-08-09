#include "includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : Form("robtomy request", 72, 45), _target(target) {
	Bureaucrat::VerboseMsg("RobotomyRequestForm Targeted Constructor called");
	std::srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form(src), _target(src.getTarget()) {
	Bureaucrat::VerboseMsg("RobotomyRequestForm Copy Constructor called");
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	Bureaucrat::VerboseMsg("RobotomyRequestForm Destructor called");
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const & src ) {
	Bureaucrat::VerboseMsg("RobotomyRequestForm Assignation Operator called\nNeither Name nor Grades can be changed.");
	this->setSigned(src.getSigned());
	return (*this);
}

std::string const	RobotomyRequestForm::getTarget( void ) const {
	return (this->_target);
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	this->isSignedAndExecutable(executor);
	if (std::rand() % 100 < 50)
		std::cout << this->_target << " has been successfully robotomised" << std::endl;
	else
		std::cout << this->_target << "'s robotomisation failed" << std::endl;
}
