#include "includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : Form("shrubbery creation", 145, 137), _target(target) {
	Bureaucrat::VerboseMsg("ShrubberyCreationForm Targeted Constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form(src) {
	Bureaucrat::VerboseMsg("ShrubberyCreationForm Copy Constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	Bureaucrat::VerboseMsg("ShrubberyCreationForm Destructor called");
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const & src ) {
	Bureaucrat::VerboseMsg("ShrubberyCreationForm Assignation Operator called\nNeither Name nor Grades can be changed.");
	this->setSigned(src.getSigned());
	return (*this);
}

std::string const	ShrubberyCreationForm::getTarget( void ) const {
	return (this->_target);
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	std::ofstream	garden;
	std::string		name = this->_target + "_shrubbery";
	
	this->isSignedAndExecutable(executor);
	garden.open(name.data(), std::ios_base::app);
	if (!garden.is_open())
		throw "Cannot open " + name;
	garden << "	           ,@@@@@@@," << std::endl;
	garden << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	garden << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	garden << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	garden << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	garden << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	garden << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	garden << "       |o|        | |         | |" << std::endl;
	garden << "       |.|        | |         | |" << std::endl;
	garden << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
}
