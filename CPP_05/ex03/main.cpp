#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Intern.hpp"

int	main( void ) {
	Bureaucrat	Tom("Tom", 25);
	Bureaucrat	Bobby("Bobby", 5);
	Bureaucrat	Regis("Regis", 150);
	Intern		DoesntMatter;
	Form		*a38;
	Form		*b52;
	Form		*m21;	

	std::cout << Tom << std::endl;
	std::cout << Bobby << std::endl;
	a38 = DoesntMatter.makeForm("presidential pardon", "Regis");
	Regis.signForm(a38);
	Bobby.executeForm(a38);
	Tom.signForm(a38);
	Tom.executeForm(a38);
	Bobby.executeForm(a38);
	b52 = DoesntMatter.makeForm("robotomy request", "Regis");
	m21 = DoesntMatter.makeForm("death penalty", "Regis");
	Bobby.signForm(b52);
	Bobby.signForm(m21);
	return (0);
}