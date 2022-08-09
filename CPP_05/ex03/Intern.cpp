#include "includes/Intern.hpp"

t_Forms	Intern::forms[] = {
		{ "presidential pardon", &PresidentialPardonForm::writeForm},
		{ "robotomy request", &RobotomyRequestForm::writeForm},
		{ "shrubbery creation", &ShrubberyCreationForm::writeForm}
};

Intern::Intern( void ) {
	Bureaucrat::VerboseMsg("Intern Base Constructor called");
}

Intern::Intern( Intern const & src ) {
	Bureaucrat::VerboseMsg("Intern Copy Constructor called");
	*this = src;
}

Intern::~Intern( void ) {
	Bureaucrat::VerboseMsg("Intern Destructor called");
}

Intern	&Intern::operator=( Intern const & src ) {
	Bureaucrat::VerboseMsg("Intern Assignation Operator called");
	*this = src;
	return (*this);
}

Form	*Intern::makeForm( std::string const & FormName, std::string const & Target) {
	Form	*project;

	for (int i = PRESIDENTIAL; i < UNKNOWN; i++) {
		if (!Intern::forms[i].Name.compare(FormName)) {
			project = Intern::forms[i].writeForm(Target);
			std::cout << *this << " create " << *project << std::endl;
			return (project);
		}
	}
	std::cout << "Unknown Form. Intern cannot proceed." << std::endl;
	return (NULL);
}


std::ostream	&operator<<( std::ostream & ostream, Intern const & src ) {
	(void) src;
	ostream << "Intern";
	return (ostream);
}