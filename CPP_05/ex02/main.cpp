#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int	main( void ) {
	Bureaucrat				Tom("Tom", 25);
	Bureaucrat				Bobby("Bobby", 5);
	PresidentialPardonForm	a38("Regis");
	RobotomyRequestForm		b52("Regis");
	ShrubberyCreationForm	m21("Regis");
	Bureaucrat				Regis("Regis", 150);

	std::cout << Tom << std::endl;
	std::cout << Bobby << std::endl;
	Bobby.executeForm(a38);
	Tom.signForm(a38);
	Tom.executeForm(a38);
	Bobby.executeForm(a38);
	Bobby.executeForm(b52);
	Regis.signForm(b52);
	Tom.signForm(b52);
	Regis.executeForm(b52);
	Tom.executeForm(b52);
	Bobby.executeForm(b52);

	Bobby.executeForm(m21);
	Regis.signForm(m21);
	Tom.signForm(m21);
	Regis.executeForm(m21);
	Tom.executeForm(m21);
	Bobby.executeForm(m21);
	return (0);
}